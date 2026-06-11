#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

// 連長圧縮（ランレングス圧縮）：sの連長部分を{文字,個数}の配列で返す。
vector<pair<char, long long>> RunLengthEncoding(string s){
    vector<pair<char, long long>> ret;
    long long i = 0, n = s.size();
    while(i<n){
        char tmp = s[i];
        long long cnt = 1;
        while(i<n){
            i++;
            if(tmp == s[i]) cnt++;
            else break;
        }
        ret.push_back(make_pair(tmp, cnt));
    }
    return ret;
}

int main(){
    Init();
    ll n, a, b, c, d; string s;
    cin >> n >> a >> b >> c >> d >> s;
    a--, b--, c--, d--;
    bool ans = true;

    // ゴールcがdより右にあるなら、すぬけはふぬけを飛び越す必要がある。
    // 飛び越すためには[b-1, d]に何もないマスが3マス以上連続した部分が必要
    if(c > d){
        auto rle = RunLengthEncoding(s.substr(b-1, d-(b-1)+2));
        bool over3 = false;
        for(auto &p: rle){
            if(p.first == '.' && p.second >= 3) over3 = true;
        }
        if(!over3){
            ans = false;
            goto LAST;
        }
        // a -> cに石が2箇所続く部分がなければOK
        auto AtoC = RunLengthEncoding(s.substr(a, c-a+1));
        for(auto &p: AtoC){
            if(p.first == '#' && p.second >= 2){
                ans = false;
                goto LAST;
            }
        }
    }
    // 飛び越す必要が無い場合はb -> dが到達可能か確認し、その後a -> bが到達可能ならOK
    else{
        auto BtoD = RunLengthEncoding(s.substr(b, d-b+1));
        for(auto &p: BtoD){
            if(p.first == '#' && p.second >= 2){
                ans = false;
                goto LAST;
            }
        }
        auto AtoB = RunLengthEncoding(s.substr(a, b-a+1));
        for(auto &p: AtoB){
            if(p.first == '#' && p.second >= 2){
                ans = false;
                goto LAST;
            }
        }
    }
LAST:
    ans ? Yes() : No();
}