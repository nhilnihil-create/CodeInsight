#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int mod = 1000000007;
const ll INF = 1001001001;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int g[15][15];

int main(){
    int n;
    cin >> n;
    rep(i,n) rep(j,n) g[i][j] = -1;
    rep(i,n){
        int a;
        cin >> a;
        rep(j,a){
            int x,y;
            cin >> x >> y;
            x--;
            g[i][x] = y;
        }
    }

    int ans = 0;
    
    rep(i,1<<n){
        vector<int> x(n);
        rep(j,n) if(i>>j & 1) x[j] = 1;
        bool ok = true;
        rep(j,n){
            if(x[j]){
                rep(k,n){
                    if(g[j][k]==-1)continue;
                    if(g[j][k]!=x[k])ok = false;
                }
            }
        }
        if(ok) ans = max(ans,__builtin_popcount(i));
    }
    cout << ans << endl;
    return 0;
}