#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	vector<int> av(n);
	for (auto& i : av) {
		cin >> i;
	}
	vector<int> fv(n);
	for (auto& i : fv) {
		cin >> i;
	}
	sort(av.begin(), av.end());
	sort(fv.rbegin(), fv.rend());

	long long l = -1;
	long long r = LLONG_MAX-2;
	while (r - l != 1) {
		long long sum = 0;
		long long c = (r + l) / 2;
		for (int i = 0; i < n; ++i) {
			sum += max(0LL, av[i] - c / fv[i]);
		}
		if (sum <= k) {
			r = c;
		}
		else {
			l = c;
		}
	}
	cout << r << endl;

	return 0;
}