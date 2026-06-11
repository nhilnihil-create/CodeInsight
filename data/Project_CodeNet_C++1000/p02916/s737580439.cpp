#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n;
int a[N], b[N], c[N];
int ans = 0;
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> b[i];
		ans += b[i];
	}
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	for(int i = 2; i <= n; i++)
	{
		if(a[i] - a[i - 1] == 1)
			ans += c[a[i - 1]];
	}
	cout << ans;
	return 0;
}