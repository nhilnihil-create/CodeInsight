#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;
const int mod[] = {1000 * 1000 * 1000 + 7 , 1000 * 1000 * 1000 + 9};
const int base[] = {4001, 737};

int h[maxn][2] , pw[maxn][2] , n;

string s;

int get(int l , int r , int k)
{
	return (h[r][k] - 1LL * h[l][k] * pw[r - l][k] % mod[k] + mod[k]) % mod[k];
}

bool check(int len)
{
	map<pair<int , int> , int> mp;

	for(int i = 0; i + len <= n; i++)
	{
		pair<int , int> tmp = {get(i , i + len , 0) , get(i , i + len , 1)};
		if(mp.count(tmp))
		{
			if(mp[tmp] + len <= i)
				return 1;
		}
		else
			mp[tmp] = i;
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int j = 0; j < 2; j++)
	{
		pw[0][j] = 1;
		for(int i = 1; i < maxn; i++)
			pw[i][j] = 1LL * pw[i - 1][j] * base[j] % mod[j];
	}

	cin >> n >> s;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < 2; j++)
			h[i + 1][j] = (1LL * h[i][j] * base[j] + s[i]) % mod[j];

	int l = 0 , r = n;

	while(r - l > 1)
	{
		int m = (l + r) / 2;
		if(check(m))
			l = m;
		else
			r = m;
	}

	cout << l << endl;
}










 
