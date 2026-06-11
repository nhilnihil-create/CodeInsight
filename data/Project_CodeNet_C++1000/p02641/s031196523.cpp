#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
//#define mp              make_pair
#define pii             pair<int,int>
#define vec             vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define no_of_test(x)   int x; cin>>x; while(x--)

const int mod = 1e9 + 7;
void very_fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
int binary_exponentation(int a, int b)
{
	int ret = 1;
	while (b)
	{
		if (b & 1) ret = (ret * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ret;
}


int32_t main()
{
	very_fast();
	//no_of_test(x)
	{
		int x, n;
		cin >> x >> n;
		vector<int>v(n);
		unordered_map<int, int>chk;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			chk[v[i]]++;
		}
		int ans = 0;
		while (true)
		{
			if (chk[x - ans] == 0)
			{
				cout << x - ans << endl;
				return 0;
			}
			if (chk[x + ans] == 0)
			{
				cout << x + ans << endl;
				return 0;
			}
			ans++;
		}
	}
	return 0;
}



