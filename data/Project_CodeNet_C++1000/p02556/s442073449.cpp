#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD ll(1e9+7)
#define MAX_N 200005
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl


int main(){
    ll n;
    cin >> n;
    vector<ll> z(n), d(n);
    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        z[i] = x + y;
        d[i] = x - y;
    }
    sort(all(z));
    sort(all(d));
    ll ans = max(z[n-1]-z[0], d[n-1]-d[0]);
    cout << ans << endl;


    return 0;

}
