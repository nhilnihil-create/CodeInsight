#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif 

using namespace std;

#define TRACE(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << endl;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]";
	err(++it, args...);
}

#define MAXN ((int)15+5)
#define MOD ((int)1e9 + 7)
#define INF ((int)1e9 + 9)
#define ll long long
#define _ << " " <<
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define LOG(x) if(DEBUG) cerr << x << endl;
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
#define pii pair<int,int>
#define mid ((l+r)/2)

int n,m,x;
int ans = INF;
int d[MAXN][MAXN];
int c[MAXN];

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m >> x;
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i];
		for (int j = 0; j < m; ++j)
			cin >> d[i][j];
	}

	for (int i = 1; i < (1<<n); ++i)
	{
		int total[13] = {0};
		int cost = 0;
		for (int j = 0; j < n; ++j)
			if((i & (1<<j)))
			{
				cost += c[j];
				for (int k = 0; k < m; ++k)
					total[k] += d[j][k];
			}
		bool ok = true;
		for (int k = 0; k < m; ++k)
			if(total[k] < x)
			{
				ok = false;
				break;
			}

		if(ok)
			ans = min(ans, cost);
	}
	if(ans == INF)
		ans = -1;
	
	cout << ans << endl;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/