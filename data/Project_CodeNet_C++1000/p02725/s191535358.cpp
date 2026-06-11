#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k, n;
	cin>>k>>n;
	int A[n+1];
	for (int i = 1; i <= n; ++i)
	{
		cin>>A[i];
	}
	int ans[n+1];
	ans[0] = INT_MIN;
	ans[1] = A[n] - A[1];
	for (int i = 2; i <= n; ++i)
	{
		ans[i] = k - A[i] + A[i-1];
	}
	sort(ans, ans+n+1);
	cout<<ans[1]<<endl;
}