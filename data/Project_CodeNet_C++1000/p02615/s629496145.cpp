#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll mod = 1000000007;
ll a[200005];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, greater<ll>());
	ll ans = 0;
	n--;
	ll count = 0;
	ll flag = 0;
	if (n == 1) {
		cout << a[0] << endl;
		return 0;
	}
	while (n > 0) {
		if (flag == 0) {
			flag = 1;
			ans += a[count];
			count++;
			n--;
		}
		if (n - 2 >= 0) {
			ans += 2 * a[count];
			n -= 2;
			count++;
		}
		else {
			ans += a[count];
			n--;
			count++;
		}
	}
	cout << ans << endl;
	return 0;
}