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

#define MAXN ((int)1e6+5)
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

int n;
int d[MAXN];

bool pairwise()
{
	map <int, bool> mp;

	for (int i = 0; i < n; ++i)
	{
		int t = d[i];
		int dv = 2;

		while(dv * dv <= t)
		{
			if(t % dv == 0)
			{
				if(mp[dv])
					return false;
				mp[dv] = 1;
				while(t%dv==0) t /= dv;
			}

			dv++;
		}

		if(t > 1)
		{
			if(mp[t])
				return false;
			mp[t] = 1;
		}
	}

	return true;
}

bool setwise()
{
	int gcd = d[0];
	
	for (int i = 1; i < n; ++i)
		gcd = __gcd(gcd, d[i]);

	return gcd == 1;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> d[i];

	if(pairwise())
		cout << "pairwise coprime\n";
	else if(setwise())
		cout << "setwise coprime\n";
	else
		cout << "not coprime\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/