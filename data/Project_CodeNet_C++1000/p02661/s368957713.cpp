#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

const ll N = 200010;

ll n;
ll a[N], b[N];

int main(void) {
	ios::sync_with_stdio(0);  cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);

	if (n % 2) cout << b[n / 2 + 1] - a[n / 2 + 1] + 1 << endl;
	else cout << (b[n / 2 + 1] + b[n / 2]) - (a[n / 2 + 1] + a[n / 2]) + 1 << endl;

	return 0;
}