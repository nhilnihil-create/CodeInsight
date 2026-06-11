#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll mod = 1000000007;
 
int main() {
    int n;
    cin >> n;
    vector<ll>v(n+1);
    rep(i, 0, n+1)cin >> v[i];
    if(n==0){
        if(v[0]==1){
            cout << 1 << endl;
            return 0;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    if(v[0]!=0){
        cout << -1 << endl;
        return 0;
    }
    ll tot=0;
    rep(i, 0, n+1)tot += v[i];
    ll root = 1;
    ll ans = 1;
    rep(i, 1, n+1){
        root *= 2;
        if(root<v[i]){
            cout << -1 << endl;
            return 0;
        }
        ans += min(tot, root);
        root = min(tot, root) - v[i];
        tot -= v[i];
    }
    cout << ans << endl;
}