#include<bits/stdc++.h>

using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void c_p_c()
{
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int getSum(int n)
{
	int sum;


	for (sum = 0; n > 0; sum += n % 10, n /= 10);

	return sum;
}
int neighbours(int i, int j, int n, int m)
{
	int c = 0;
	if (i + 1 < n)
		c++;
	if (i - 1 >= 0)
		c++;
	if (j + 1 < m)
		c++;
	if (j - 1 >= 0)
		c++;
	return c;
}
int32_t main()
{
	FIO;
	
	int n, d;
	cin >> n >> d;
	vector<vector<int>>ve(n, vector<int>(d));
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < d; j++)
			cin >> ve[i][j];
	int ans = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			int a = 0;
			for (int k = 0; k < d; k++)
			{
				int diff = abs(ve[i][k] - ve[j][k]);
				a += diff * diff;
			}
			bool be = false;;
			for (int k = 0; k <= a; k++)
			{
				if (k * k == a)
					be = true;
			}
			if (be) ans++;
		}
	}

	cout << ans;
}








