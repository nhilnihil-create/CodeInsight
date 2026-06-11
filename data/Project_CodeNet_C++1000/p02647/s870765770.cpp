#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> av(n);
	for (auto& a : av) {
		cin >> a;
	}

	for (int ki = 0; ki < k; ++ki)
	{
		vector<int> bv(n+1, 0);
		for (int i = 0; i < n; ++i) {
			int l = max(0, i - av[i]);
			int r = min(i + av[i] + 1, n);
			++bv[l];
			--bv[r];
		}

		for (int i = 0; i < n; ++i) {
			bv[i + 1] += bv[i];
		}

		bv.pop_back();

		if (av == bv) {
			break;
		}
		av.swap(bv);
	}

	for (auto& a : av) {
		cout << a << " ";
	}
	cout << endl;

	return 0;
}