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

#define MAXN ((int)2e5+5)
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
vector <int> a,b;

int get_mean(vector<int>& v)
{
	int t = (v.size()-1) / 2;
	return (v[t] + v[t+1]);
}

int get_mean_odd(vector<int>& v)
{
	int t = (v.size()) / 2;
	return v[t];
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];

	sort(all(a));
	sort(all(b));

	if(n%2 == 0)
	{
		int mn = get_mean(a);
		int mx = get_mean(b);

		cout << (mx - mn) + 1 << endl;
	}
	else
	{
		int mn = get_mean_odd(a);
		int mx = get_mean_odd(b);

		cout << (mx - mn) + 1 << endl;
	}

}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/