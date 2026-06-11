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
    string s; cin >> s; s += ";";
    auto rle = RunLengthEncoding(s);
    ll ans = 0, n = rle.size(), pre = 0;
    for(ll i=0; i<n; i++){
        if(rle[i].first == '>'){
            // >
            ans += (ll)(rle[i].second * (rle[i].second+1.0)/2.0);
            if(rle[i].second < pre){
                ans = ans + pre - rle[i].second;
            }
        }
        else if(rle[i].first == '<'){
            // <
            ans += (ll)((rle[i].second-1.0) * rle[i].second/2.0);
            pre = rle[i].second;
        }
        else{
            // ;
            if(rle[i-1].first == '<') ans += pre;
        }
    }
    cout << ans << endl;
}