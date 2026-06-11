#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 1e5 + 5;
const ll LINF = 1e18 + 5;
int n, a[N], p[N];
int l1[N], l2[N], r1[N], r2[N]; 
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n;
 	for(int i=1; i<=n; i++)
 	{
 		cin >> a[i];
 		p[a[i]] = i;
 	}
 	set <int> s;
 	for(int i=1; i<=n; i++) s.insert(i);
 	for(int i=1; i<=n; i++)
 	{
 		s.erase(p[i]);
 		auto it = s.lower_bound(p[i]);
 		if(it!=s.end())
 		{
 			int x = *it;
 			r1[i] = x;
 			s.erase(it);
 			auto it2 = s.lower_bound(p[i]);
 			if(it2!=s.end()) r2[i] = *it2;
 			else r2[i] = n+1;
 			s.insert(x);
 		}
 		else r1[i] = r2[i] = n+1;
 	}
 	for(int i=1; i<=n; i++) s.insert(i);
 	for(int i=1; i<=n; i++)
 	{
 		s.erase(p[i]);
 		auto it = s.lower_bound(p[i]);
 		if(it!=s.begin())
 		{
 			--it;
		 	int x = *it;
 			l1[i] = x;
 			s.erase(it);
 			auto it2 = s.lower_bound(p[i]);
 			if(it2!=s.begin()) l2[i] = *(--it2);
 			else l2[i] = 0;
 			s.insert(x);
 		}
 		else l1[i] = l2[i] = 0;
 	}
 	ll ans = 0;
 	for(int i=1; i<=n; i++)
 	{
 		//cout << l2[i] << ' ' << l1[i] << ' ' << r1[i] << ' ' << r2[i] << '\n';
 		ans += 1ll * (l1[i]-l2[i]) * (r1[i]-p[i]) * i;
 		ans += 1ll * (p[i]-l1[i]) * (r2[i]-r1[i]) * i;
 	}
 	cout << ans;
	return 0;
}
