#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n; cin >> n;
	vector <int> d(n);
	rep(i, n) cin >> d[i];
	int ans = 0;
	rep(i, n)
	{
		for (int j = i + 1; j < n; j++)
		{
			ans += d[i]*d[j];
		}
	}
	cout << ans << endl;
	return (0);
}