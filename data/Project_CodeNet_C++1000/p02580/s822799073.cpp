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

#define MAXN ((int)3e5+5)
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

int n,m,k;
map <int, map<int,int>> mp;

int r[MAXN];
int c[MAXN];

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i)
	{
		int a,b;
		cin >> a >> b;
		mp[a][b]++;

		r[a]++;
		c[b]++;
	}

	int rmax = 0;
	int cmax = 0;
	
	vector <int> ridx, cidx;

	for (int i = 0; i < MAXN; ++i)
	{
		if(rmax < r[i])
		{
			rmax = r[i];
			ridx.clear();
			ridx.pb(i);
		}
		else if(rmax == r[i])
		{
			ridx.pb(i);
		}

		if(cmax < c[i])
		{
			cmax = c[i];
			cidx.clear();
			cidx.pb(i);
		}
		else if(cmax == c[i])
		{
			cidx.pb(i);
		}
	}

	bool f = 1;

	for (int x : ridx)
	{
		for (int y : cidx)
			if(mp[x][y] == 0)
			{
				f = 0;
				break;
			}

		if(f == 0) break;
	}

	cout << rmax + cmax - (f) << endl;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/