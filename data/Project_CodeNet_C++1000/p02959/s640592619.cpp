#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>



using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
int main()
{
	int n; cin >> n;
	vector<ll> a(n + 1);
	vector<ll> b(n);
	ll sum = 0;
	rep(i, n+1) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n+1)
		sum += a[i];
	rep(i, n) {
		if (a[i] > b[i]) {
			a[i] -= b[i];
			continue;
		}
		else if (a[i] < b[i]) {
			b[i] -= a[i];
			a[i] = 0;
			if (a[i + 1] > b[i]) {
				a[i + 1] -= b[i];

			}
			else
				a[i + 1] = 0;
		}
		else {
			a[i] = 0;
			b[i] = 0;
		}
	}
		ll sa = 0;
		rep(i, n+1)
		sa += a[i];
		cout << sum - sa;
	
}
