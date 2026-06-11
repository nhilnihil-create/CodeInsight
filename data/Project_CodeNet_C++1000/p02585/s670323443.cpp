#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    ll n, k; cin >> n >> k;
    vector<ll> P(n), C(n);
    rep(i, n){cin >> P[i]; P[i]--;}
    rep(i, n)cin >> C[i];

    ll res = -LINF;
    rep(i, n){
        //サイクルスコアとサイクル長を調べる
        ll cycle_score = 0; int cycle_len = 0, v = i;
        while(1){
            cycle_len++;
            v = P[v];
            cycle_score += C[v];
            if(v == i)break;
        }
        //非サイクル部を全探索してスコアを比較する。スコア＝非サイクル部のスコア+サイクルスコア
        ll score = 0; int cnt = 0;
        while(1){
            cnt++;
            v = P[v];
            score += C[v];
            if(cnt > k)break;

            ll sum = score + max(0LL, cycle_score) * ((k - cnt) / cycle_len);
            chmax(res, sum);
            if(v == i)break;
        }
    }
    cout << res << ln;
}
    
