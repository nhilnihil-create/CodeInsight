#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, k; cin >> n >> k;
	vector<double> e(n);
	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		e[i] = (double)(p + 1) / 2;
	}
	double sum = 0;
	int tmp_k = k;
	for (int i = 0; i < k; i++) {
		sum += e[i];
	}
	double ans = sum;
	for (int i = k ; i < n; i++) {
		sum += e[i];
		sum -= e[i - k];
		ans = max(ans, sum);
	}
	cout << fixed << setprecision(11) << ans << endl;
    return 0;
}