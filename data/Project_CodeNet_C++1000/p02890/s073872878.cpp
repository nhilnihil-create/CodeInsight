#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define all(a) (a).begin(),(a).end()
#define double long double
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(all(a));
	vector<int> cnt;
	int s = 1, p = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] == p) s++;
		else {
			cnt.push_back(s);
			s = 1;
			p = a[i];
		}
	}
	cnt.push_back(s);
	int ns = cnt.size();
	for (int i = 0; i < n - ns; i++) cnt.push_back(0);
	sort(all(cnt));
	reverse(all(cnt));
	vector<int> sum(n);
	for (int i = 0; i < n; i++) sum[0] += cnt[i];
	for (int i = 1; i < n; i++) sum[i] = sum[i - 1] - cnt[i - 1];
	vector<int> res(n + 2);
	vector<double> frac(n + 2);
	for (double i = 0; i < n + 2; i++) {
		frac[i] = (double)(i / (i + 1));
	}
	for (int i = 1; i < n + 2; i++) {
		if (sum[i] != 0) {
			double ch = (double)sum[i] / (double)sum[i - 1] - 0.000000000001;
			int x = lower_bound(all(frac), ch) - frac.begin();
			res[i] = i + x - 1;
		}
		else {
			res[i] = res[i - 1] + 1;
		}
	}
	int t = 1, y = 0;
	for (int i = 0; i < n; i++) {
		while (i >= res[t]) {
			t++;
		}
		cout << sum[t - 1] / (i + 2 - t) << endl;
	}
}