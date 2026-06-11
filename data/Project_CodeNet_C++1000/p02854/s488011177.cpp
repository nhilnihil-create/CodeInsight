#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n;i++)
int main() {
	ll n, ans = 1e16,sum = 0 ,S =0;cin >> n;vector<ll>a(n + 1);
	rep(i, n) {
		cin >> a[i];
		S += a[i];
	}
	rep(i, n) {
		sum += a[i];
		ans = min(ans, abs(2 * sum - S));
	}
	cout << ans << endl;
}