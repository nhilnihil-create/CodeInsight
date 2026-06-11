#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>
#define vvl vector<vector<long long>>
#define all(A) A.begin(), A.end()

int main() {
    ll n, x, y; cin >> n >> x >> y;
    x--; y--;

    vvl g(n, vl(n));
    vl ans(n);

    g[x][y] = 1;
    rep(i,n){
        xrep(j,i+1,n){
            g[i][j] = min(j - i, abs(i-x) + 1 + abs(j-y));
            ans[g[i][j]-1]++;
        }
    }
    
    rep(i,n-1) cout << ans[i] << endl;
}