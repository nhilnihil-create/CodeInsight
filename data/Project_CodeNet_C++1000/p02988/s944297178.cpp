#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int  main()
{
	int n; cin >> n;
	vector<int> p(n);
	int cnt = 0;
	rep(i, n)
	{
		cin >> p[i];
	}
	for (int i = 1; i < n - 1; i++)
	{
		priority_queue<int> q;
		q.push(p[i-1]);q.push(p[i+1]);q.push(p[i]);
		q.pop();
		if (q.top() == p[i])
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}
