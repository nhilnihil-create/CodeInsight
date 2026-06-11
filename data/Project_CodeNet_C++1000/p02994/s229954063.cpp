#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int n; cin >> n; //L+i−1
	int l ; cin >> l;
	int deli[n+1];
	int sum = 0;
	rep1(i, n)
	{
		deli[i] = l+i-1;
		sum += deli[i];
	}
	int ans = INT_MAX;
	rep1(i, n)
	{
		ans = min(abs(sum - (sum-deli[i])), ans);
		// cout << deli[i] << endl;
	}
	if (sum < 0)
		cout << sum + ans << endl;
	else
		cout << sum - ans << endl;
	return (0);
}