#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <complex>

using namespace std;
using Arrow = complex<long long>;

class Solution {
public:
	long double engines(vector<Arrow>& arrows) {
		const int n = arrows.size();
		sort(arrows.begin(), arrows.end(), [](const auto& a, const auto& b) { return atan2(a.imag(), a.real()) < atan2(b.imag(), b.real()); });
#if 0
		cout << "Input in sorted: " << endl;
		for (auto arrow : arrows)
			cout << arrow << endl;
		cout << endl;
#endif
		Arrow curr(0, 0);
		long long ans = 0;
		int R = 0;
		for (int L = 0; L < n; ++L) {
			if (L > R)
				R = L, curr = Arrow(0, 0);
			while (R < L + n && norm(curr + arrows[R % n]) >= norm(curr))
				curr += arrows[R++ % n];
			ans = max(ans, norm(curr)), curr -= arrows[L % n];
		}
		return sqrt(ans);
	}
};

int main() {
	int n;
	cin >> n;

	vector<Arrow> arrows(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		arrows[i] = Arrow(x, y);
	}

	Solution sol;
	long double ans = sol.engines(arrows);
	cout << fixed << setprecision(50) << ans << endl;
	return 0;
}
