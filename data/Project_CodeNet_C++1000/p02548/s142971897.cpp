// In The Name Of God

#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long

using namespace std;

int n;
const int maxn = 1e2 + 100;
int a[maxn], b[maxn], ans, maxx;

int main()
{
    IOS;
    cin >> n;

	for(int i = 1; i <= n; i ++)
	{
		int j = 1;
		while(i * j < n)
		{
		//	cout << i << ' ' << j << endl;
			j ++;
			ans ++;
		}
	}
	return cout << ans << endl, 0;
}
