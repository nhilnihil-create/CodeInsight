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
    vector<vector<int>> D(n, vector<int>(2));
    rep(i, n){
        rep(j, 2){
            cin >> D[i][j];
        }
    }
    bool fg = false;
    rep(i, n-2){
        if(D[i][0]==D[i][1] && D[i+1][0]==D[i+1][1] && D[i+2][0]==D[i+2][1])fg = true;
    }
    if(fg)cout << "Yes" << ln;
    else cout << "No" << ln;
}

