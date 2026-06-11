/******

AUTHOR : RUDRANSH TRIPATHI, IIIT NAGPUR, CCID(rt24) & CFID(rsgt24)

MOTTO : Use criticism as fuel and you will never run out of energy.
        AIM : TO BECOME A BETTER CODER
        INTROSPECT + COURSE CORRECTIONS = CATALYST FOR SUCCESS
        Every moment is an opportunity to better yourself

*******/

#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int MAX = 1e5 + 5;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long int
#define pb push_back
#define d(x) cout<<x<<"\n"
#define time_passed	1.0 * clock() / CLOCKS_PER_SEC

//basic mathematics
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

//modular arithmetic
int powermod(int x, int y, int p)
{
	int res = 1;

	x = x % p;

	if (x == 0) return 0;

	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

//Prime numbers till n precomputation - range query
int prefix[MAX + 1];

void buildPrefix()
{
	bool prime[MAX + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= MAX; p++) {
		if (prime[p] == true) {
			for (int i = p * 2; i <= MAX; i += p)
				prime[i] = false;
		}
	}
	prefix[0] = prefix[1] = 0;
	for (int p = 2; p <= MAX; p++) {
		prefix[p] = prefix[p - 1];
		if (prime[p])
			prefix[p]++;
	}
}

int query(int L, int R)
{
	return prefix[R] - prefix[L - 1];
}


//Find all paths from a to b in an undirected graph
vector<int> g[MAX];
int visited[MAX];
//count of all the paths from 1 to n;

void dfs(int visited[MAX], int u, int v, vector<int> path)
{
	visited[u] = 1;
	if (u == v)
	{
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		for (int i = 0; i < g[u].size(); i++)
		{
			int y = g[u][i];

			if (visited[y] == 0)
			{
				visited[y] = 1;
				path.pb(y);
				dfs(visited, y, v, path);
				path.pop_back();
			}

		}
	}

	visited[u] = 0;

}

vector<int> graph[MAX];
int vis[MAX];

void dfs(int v)
{
	vis[v] = 1;
	
	for(auto x: graph[v]){
	    
		if(vis[x] == 0)
		{
		    dfs(x);
		}
		
	}
}

int dp[20001];

void pre()
{
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 1;
    
    for(int i = 4; i <= 2000; i++)
    {
        dp[i] = (dp[i - 1] % M + dp[i - 3] % M) % M;
    }
}

void solve()
{
	int n;
	cin >> n;
	int k = n;
	int xx[n];
	int yy[n];
	int i = 0;
	while(n--)
	{
	    int x,y;
	    cin >> x >> y;
	    xx[i] = x + y;
	    yy[i] = x - y;
	    i++;
	}
	
	int max_1x = *max_element(xx,xx+i);
	int min_1x = *min_element(xx,xx+i);
	int max_1y = *max_element(yy,yy+i);
	int min_1y = *min_element(yy,yy+i);
	
	cout << max(max_1x - min_1x, max_1y - min_1y) << "\n";
	
		
		
	//for (int i = 0; i < n; i++)
	//	cout << ar[i];
}

int32_t main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    pre();
	fastio
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	//cerr << "\n" << "Time elapsed : " << time_passed << "\n";
	return 0;
}