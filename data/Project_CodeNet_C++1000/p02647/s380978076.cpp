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
	int k; cin >> k;
	vector <int> a(n);
	rep(i, n) cin >> a[i];
	rep(j, k)
	{
		vector <int> b(n+1);
		rep(i, n)
		{
			int l = max(i-a[i], 0);
			int r = min(i+a[i], n-1);
			b[l]++;
			if (r < n+1)
				b[r+1]--;
		}
		for(int i = 1; i < n; i++)
			b[i] += b[i-1];
		if (a == b)
			break;
		a = b;
	}
	rep(i, n)
		cout << a[i] << " ";
	cout << endl;
	return (0);
}