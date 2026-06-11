#include <bits/stdc++.h>
using namespace std;
 
static const long long int INF = ((1ll<<60)-1);
 
int main()
{
	long long int a, b, m;
	cin >> a >> b >> m;
	long long int A[100001], B[100001];
	long long int mir = INF, mid = INF;
	for (long long int i = 1; i <= a; ++i)
	{
		cin >> A[i];
		mir = min(mir, A[i]);
	}
	for (long long int i = 1; i <= b; ++i)
	{
		cin >> B[i];
		mid = min(mid, B[i]);
	}
	long long int x, y, c;
	long long int ans = INF;
	for (long long int i = 0; i < m; ++i)
	{
		cin >> x >> y >> c;
		ans = min(ans, A[x] + B[y] - c);
	}
	cout << min(mir + mid, ans) << endl;
	return 0;
}