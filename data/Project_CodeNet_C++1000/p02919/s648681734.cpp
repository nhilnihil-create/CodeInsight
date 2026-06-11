#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif 

using namespace std;

#define MAXN ((int)2e5+5)
#define MOD ((int)1e9 + 7)
#define INF ((int)1e9 + 9)
#define ll long long
#define _ << " " <<
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define TRACE(x) if(DEBUG) cerr << #x << " = " << x << endl;
#define TRACE2(x,y) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << endl;
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
#define pii pair<int,int>
#define mid ((l+r)/2)

ll n;
ll d[MAXN];
ll place[MAXN];

ll ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> d[i];
		place[d[i]] = i;
	}

	multiset <ll> st = {0,0,n+1,n+1};

	for (int i = n; i > 0; --i)
	{
		auto it = st.insert(place[i]);

		ll k = place[i];

		ll l1 = *(--it);
		ll l2 = *(--it); 

		ll r1 = *++(++(++(it)));
		ll r2 = *(++it);

		ans += ((k-l1) * (r2 - r1) + (l1 - l2) * (r1-k)) * i; 
	}
	
	cout << ans << endl;
}