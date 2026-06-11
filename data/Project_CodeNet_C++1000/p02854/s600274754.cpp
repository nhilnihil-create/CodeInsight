#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
int a[MX], b[MX], c[MX];

signed main(){
    int n;
    cin >> n;
    
    rep(i,n) cin >> a[i];

    b[0] = a[0];
    FOR(i,1,n) {
        b[i] += a[i] + b[i-1];
    }

    c[n-1] = a[n-1];
    RFOR(i,n-2,0) {
        c[i] += a[i] + c[i+1];
    }

    int m = 20202020200;
    rep(i,n) {
        m = min(m, abs(b[i]-c[i+1]));
    }
    cout << m << endl;

    return 0;
}