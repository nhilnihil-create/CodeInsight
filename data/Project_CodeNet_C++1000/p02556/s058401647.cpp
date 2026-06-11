#include <bits/stdc++.h>
#define maxn 202333
using namespace std;
const auto int_limits = numeric_limits<int> ();
long long x[maxn], y[maxn];
int main() {
	long long n, Mia, Maa, Mib, Mab;
	Mia = Mib = int_limits.max();
	Maa = Mab = int_limits.min();
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
	for(int i = 1; i <= n; ++i) {
		Mia = min(Mia, x[i] - y[i]);
		Maa = max(Maa, x[i] - y[i]);
		Mib = min(Mib, x[i] + y[i]);
		Mab = max(Mab, x[i] + y[i]);
	}
	cout << max(Maa - Mia, Mab - Mib);
	return 0;
}