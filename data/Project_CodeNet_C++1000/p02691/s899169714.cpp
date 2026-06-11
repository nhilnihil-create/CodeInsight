#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 2e5 + 5;
int n, a[M];
 
int32_t main() 
{
	ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	cin >> n;
	unordered_map <int, int> add, sub;
	for(int i = 1; i <= n; i++)	
	{
		cin >> a[i];
		sub[i - a[i]]++;
		add[a[i] + i]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans += add[i - a[i]];
		ans += sub[a[i] + i];
	}
	cout << ans / 2;
    	return 0;
}