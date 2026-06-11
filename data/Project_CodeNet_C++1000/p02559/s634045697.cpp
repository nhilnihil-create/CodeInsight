#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main()
{
	int64_t n, q;
	cin >> n >> q;
	vector<int64_t> as(n);
	for (auto &&a : as)
	{
		cin >> a;
	}
	vector<int64_t> ts(q), xs(q), ys(q);
	for (int64_t i = 0; i < q; i++)
	{
		cin >> ts[i] >> xs[i] >> ys[i];
	}

	fenwick_tree<int64_t> fw(n);
	for (int64_t i = 0; i < n; i++)
	{
		fw.add(i, as[i]);
	}

	for (int64_t i = 0; i < q; i++)
	{
		if (ts[i] == 1)
		{
			cout << fw.sum(xs[i], ys[i]) << endl;
		}
		else
		{
			fw.add(xs[i], ys[i]);
		}
	}

	return 0;
}