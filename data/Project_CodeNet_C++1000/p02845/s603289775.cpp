#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll x;
    vector<ll> a(3, -1);
    ll ans = 1;
    for(int i=0;i<n;i++){
    	cin >> x;
    	ll ret = 0;
    	for(int j=0;j<3;j++) if(a[j] == x - 1) ret++;
    	ans *= ret;
        for(int j = 0;j<3;j++) {
        	if(a[j] == x - 1) {
        		a[j]++;
        		j = 1919;
        	}
        }
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}
