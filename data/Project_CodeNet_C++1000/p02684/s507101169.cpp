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
    int n; ll k; cin >> n >> k;
    vector<ll> A(n); rep(i, n) cin >> A[i], A[i]--;

    //ダブリング
    vector<vector<ll>> D(60, vector<ll>(n));
    rep(i, n)D[0][i] = A[i];
    rept(i, 1, 60){
        rep(j, n){
            D[i][j] = D[i-1][D[i-1][j]];
        }
    }

    int v = 0;
    rep(i, 60){
        if(k&1){
            v = D[i][v];
        }
        k /= 2;
    }
    cout << v + 1 << ln;
}
    
