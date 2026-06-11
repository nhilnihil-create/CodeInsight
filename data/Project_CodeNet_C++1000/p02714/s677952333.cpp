#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 4005;

int n;
char s[N];
int a[N];
int pref[N][5], suf[N][5];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		if(s[i] == 'R')
			a[i] = 0;
		else if(s[i] == 'G')
			a[i] = 1;
		else
			a[i] = 2;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= 2; j++)
			pref[i][j] = pref[i - 1][j];
		pref[i][a[i]]++;
	}
	int ans = pref[n][0] * pref[n][1] * pref[n][2];
	for(int i = 2; i < n; i++)
	{
		int k = 1;
		while(i - k >= 1 && i + k <= n)
		{
			map<int, int> f;
			f[a[i]]++;
			f[a[i - k]]++;
			f[a[i + k]]++;
			if(f.size() == 3)
				ans--;
			k++;
		}
	}
	cout << ans;
	return 0;
}
