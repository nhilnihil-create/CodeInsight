#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <complex>

using namespace std;
using LL = long long;
using Arrow = complex<LL>;

class Solution {
public:
	double engines(vector<Arrow>& arrows) {
		const int n = arrows.size();
		auto compareAngle = [](const auto& a, const auto& b) {
			return atan2(imag(a), real(a)) < atan2(imag(b), real(b));
		};
		sort(arrows.begin(), arrows.end(), compareAngle);

		Arrow window(0, 0);
		LL ans = 0;
		int R = 0;
		for (int L = 0; L < n; ++L) {
			if (R < L)
				R = L, window = Arrow(0, 0);
			while (R - L < n && norm(window + arrows[R % n]) >= norm(window))
				window += arrows[R % n], ++R;
			ans = max(ans, norm(window)), window -= arrows[L % n];
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
	double ans = sol.engines(arrows);
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
