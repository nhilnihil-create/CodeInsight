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
    int n; cin >> n;
    int F[65][2]; rep(i, 65)rep(j, 2)F[i][j] = 0;
    rep(i, n){
        ll a; cin >> a;
        rep(j, 60){
            if((a >> j)& 1)F[j][1]++;
            else F[j][0]++;
        }
    }
    ll res = 0;
    rep(i, 60){
        ll a = F[i][0], b = F[i][1];
        ll sum = (a * b) % MOD;
        sum = (sum * ((1LL << i) % MOD)) % MOD;
        res = (res + sum) % MOD;
    }
    cout << res << ln;
}
    
