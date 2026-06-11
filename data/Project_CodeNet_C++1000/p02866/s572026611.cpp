#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 998244353;
using ll = long long;
using P = pair<ll, ll>;
double PI = acos(-1);



signed main(){
    int n;
    cin >> n;
    vector<int> d(n);
    map<int, int> m;
    int ma = 0;
    rep(i, n) {
        cin >> d[i];
        d[i];
        if(d[i]>=n) {
            cout << 0 << endl;
            return 0;
        }
        m[d[i]]++;
        ma = max(d[i],ma);
        //cout << d[i]<<" "<<m[d[i]] << endl;
    }

    int now = 0;
    ll ans = 1;
    if(d[0] != 0 || m[0] != 1) {
        cout << 0 << endl;
        return 0;
    }
    FOR(i, 1, ma+1) {
        //cout << m[i] << endl;
        if(m[i]==0){
            cout << 0 << endl;
            return 0;
        }
        if(i==1) continue;
        rep(j, m[i]) {
            ans *= m[i-1];
            ans %= mod; 
        }
        //cout << ans << endl;
    }
    cout << ans << endl;


    return 0;
}

