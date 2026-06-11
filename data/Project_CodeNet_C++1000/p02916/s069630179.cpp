#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

// #define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;

using P = pair<int, int>;


vector<int> to[100005];
int cost[100005];
signed main(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n-1);

    rep(i,n) {
        cin >> a[i];
        a[i]--;
    }
    rep(i,n) cin >> b[i];
    rep(i,n-1) cin >> c[i];

    int ans = b[a[0]];
    FOR(i, 1, n) {
        if(a[i-1]+1==a[i]) {
            ans += c[a[i]-1];
        }
        ans += b[a[i]];
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}

