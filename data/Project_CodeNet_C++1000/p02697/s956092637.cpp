#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

int main() {
	ll n, m;
	cin >> n >> m;
	if (n % 2 == 1) {
		ll a = n / 2;
		ll b = a + 1;
		for (ll i = 0; i < m; ++i) {
			cout << a - i << " " << b + i << endl;
		}
	} else {
		ll a = 1;
		ll b = n - 1;
		rep(i,m){
			if(i == (n/2 - 1)/2){
				b--;
			}
			cout << a + i << " " << b - i << endl;
		}
	}
	
	return 0;
}

