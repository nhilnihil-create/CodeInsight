#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

int  main()
{
	int n,x ; cin >> n >> x;
	vector<int> l(n);
	rep(i, n)
	{
		cin >> l[i];
	}
	int ans = 0;
	vector<int> q;
	q.push_back(0);
	rep1(i, n)
	{
		ans = l[i-1] + q.back();
		q.push_back(ans);
		// cout << ans << endl;
	}
	int cnt = 0;
	rep(i, q.size())
	{
		if (q[i] <= x)
			cnt++;
	}
	cout << cnt << endl;
	return (0);
}
