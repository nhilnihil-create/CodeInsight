#include <iostream>
#include <vector>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

const ll MAX = 1e18;
int n;
int main() {
	cin >> n;
	vector<ll> a(n);
	rep(i, 0, n){
		ll tmp; cin >> tmp;
		if(tmp==0){
			cout << 0 << endl;
			return 0;
		}
		a[i] = tmp;
	}

	long double log = 0;
	rep(i, 0, n) log += log10(a[i]);
	if(log > 18) {
		cout << "-1" << endl;
		return 0;
	}

	ll ans = 1;
	rep(i, 0, n){
		ans *= a[i];
		if(ans > MAX){
			cout << "-1" << endl;
			return 0;
		}
	}

	cout << ans << endl;

    return 0;
}
