#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
int main(){
    int A, B, m;
    cin >> A >> B >> m;
    vector<ll> a(A), b(B);
    rep(i,A)cin >> a[i];
    rep(i,B)cin >> b[i];
    ll res = 1e12;
    rep(i,m){
        ll x, y, c;
        cin >> x >> y >> c;
        res = min(res, a[x-1] + b[y-1] - c);
    }
    ll ma = *min_element(all(a)), mb = *min_element(all(b));
    res = min(res, ma + mb);
    cout << res << endl;
    return 0;
}