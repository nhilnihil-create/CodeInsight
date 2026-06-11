// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 200000;

int aa[N + 1], ii[N + 1];

int main() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a, a--;
		aa[i] = (aa[i - 1] + a) % k;
		ii[i] = i;
	}
	n++;
	sort(ii, ii + n, [] (int i, int j) { return aa[i] < aa[j] || aa[i] == aa[j] && i < j; });
	long long ans = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && aa[ii[j]] == aa[ii[i]] && ii[j] - ii[i] < k)
			j++;
		ans += j - i - 1;
	}
	cout << ans << '\n';
	return 0;
}
