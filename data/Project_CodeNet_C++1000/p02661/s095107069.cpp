#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    sort(all(a));
    sort(all(b));

    ll ans;
    if(n%2==1){
        ll meda = a[n/2];
        ll medb = b[n/2];
        ans = medb - meda + 1;
    }else{
        ll meda2 = (a[n/2-1] + a[n/2]);
        ll medb2 = (b[n/2-1] + b[n/2]);
        ans = (ll)(medb2 - meda2 + 1);
    }

    cout << ans << endl;
    return 0;
}
