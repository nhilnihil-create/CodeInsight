#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	long long n, m, k;
	cin >> n >> m >> k;

	vector<long long> av(n);
	for (auto& a : av) {
		cin >> a;
	}
	vector<long long> bv(m);
	for (auto& b : bv) {
		cin >> b;
	}

	long long ret = 0;
	{
		long long ai = 0;
		long long bi = 0;
		long long c = 0;

		while (c <= k) {
			if (ai < n) {
				c += av[ai++];
			}
			else {
				break;
			}
		}

		while (c <= k) {
			if (bi < m) {
				c += bv[bi++];
			}
			else {
				break;
			}
		}

		if (c <= k) {
			cout << n + m << endl;
			return 0;
		}

		while (0 < ai) {
			c -= av[--ai];
			if (k < c) {
				continue;
			}

			while (c <= k) {
				if (bi < m) {
					c += bv[bi++];
				}
				else {
					break;
				}
			}

			if (c <= k) {
				ret = max(ai + bi, ret);
			}
			else {
				ret = max(ai + bi - 1, ret);
			}
		}
	}

	swap(n, m);
	av.swap(bv);

	{
		long long ai = 0;
		long long bi = 0;
		long long c = 0;

		while (c <= k) {
			if (ai < n) {
				c += av[ai++];
			}
			else {
				break;
			}
		}

		while (c <= k) {
			if (bi < m) {
				c += bv[bi++];
			}
			else {
				break;
			}
		}

		if (c <= k) {
			cout << n + m << endl;
			return 0;
		}

		while (0 < ai) {
			c -= av[--ai];
			if (k < c) {
				continue;
			}

			while (c <= k) {
				if (bi < m) {
					c += bv[bi++];
				}
				else {
					break;
				}
			}

			if (c <= k) {
				ret = max(ai + bi, ret);
			}
			else {
				ret = max(ai + bi - 1, ret);
			}
		}
	}


	cout << ret << endl;

	return 0;
}