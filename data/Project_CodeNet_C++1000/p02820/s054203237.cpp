#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//相手の出した手に応じて自分の出す手を決める
char select(char h){
    if(h=='r') return 'p';
    if(h=='p') return 's';
    if(h=='s') return 'r';
}

int rsp[3]; 
//自分の出した手に応じて得点を得る
int point(char h){
    if(h=='r') return rsp[0];
    if(h=='s') return rsp[1];
    if(h=='p') return rsp[2];
}

int main(){ 
    int n, k; cin >> n >> k;
    rep(i, 3) cin >> rsp[i];
    string t; cin >> t;

    int res = 0;
    vector<char> his;//出した手
    rep(i, k){
        char c = select(t[i]);
        res += point(c);
        his.push_back(c);
    }
    rept(i, k, n){
        char c = select(t[i]);
        if(his[i-k] == c) his.push_back('?');
        else{
            res += point(c);
            his.push_back(c);
        }
    }
    cout << res << ln;
}