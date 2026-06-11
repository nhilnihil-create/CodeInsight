#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)
		cin >> a[i];
	vector<int> b(n);
	map<int , int> mp;
	rep(i, n)
	{
		cin >> b[i];
		mp[i+1] = b[i];
	}
	vector<int> c(n-1);
	rep(i,n-1)
		cin >> c[i];
	// deque<int> q;
	int sum = 0;
	rep(i, n)
	{
		sum += mp[a[i]];
		if (i < n-1 && a[i+1]- a[i] == 1)
		{
			sum += c[a[i]-1];
		}
	}
	cout << sum << endl;
	return (0);
}
