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
    int n, m; cin >> n >> m;
    vector<ll> H(n); rep(i, n)cin >> H[i];
    vector<vector<ll>> G(n);
    rep(i, m){
        ll a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int res = 0;
    rep(i, n){
        bool ok = true;
        for(auto e: G[i]){
            if(H[i] <= H[e])ok = false;
        }
        if(ok)res++;
    }
    cout << res << ln;
}
