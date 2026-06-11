#include<iostream>
#include<math.h>
#include<algorithm>
typedef long long ll;

using namespace std;

ll n, a, b;
ll x[200005], y[200005], z[200005];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		x[i] = a + b;
		y[i] = a - b;
		z[i] = b - a;
	}
	sort(x, x + n); sort(y, y + n); sort(z, z + n);
	cout << max((x[n - 1] - x[0]), max((y[n - 1] - y[0]), (z[n - 1]-z[0])));
	return 0;
}