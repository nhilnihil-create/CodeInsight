#include <bits/stdc++.h>
using namespace std;

#define FREP(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FREP(i,0,n)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define endl "\n"
#define ll long long
#define vi vector<ll>
#define si set<ll>
#define mi map<ll,ll>
#define bs binary_search
#define pri(a,n) REP(i,n)cout<<a[i]<<" ";
#define all(x) x.begin(),x.end()
#define sz(a) (ll)a.size()
#define sa(a,n) sort(a,a+n)
#define sra(a,n) sort(a,a+n,greater<ll>())
#define sv(v) sort(all(v))
#define srv(v) sort(v.rbegin(),v.rend())
#define sp(x) setprecision(x)
#define mem(a) memset(a,-1,sizeof(a))
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void g_o_a_l()
{
	ll n, k, q;
	string s;
	cin >> n >> k;
	if (n <= k)
		cout << min(k - n, n);
	else
	{
		if (n % k == 0)
			cout << 0;
		else
		{
			cout << min(n % k, k - (n % k));
		}
	}
}

int main()
{
	FASTIO;

	int t = 1;
	// cin >> t;
	while (t--)
	{
		g_o_a_l();
	}

	return 0;
}