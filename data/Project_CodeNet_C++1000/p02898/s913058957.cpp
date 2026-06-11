#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int n, k; cin >> n >> k;
	vector<int> h(n);
	int ans = 0;
	rep(i,n)
	{
		int d;
		cin >> d;
		if (d >= k)
			ans++;
	}
	cout << ans << endl;
	return (0);
}
