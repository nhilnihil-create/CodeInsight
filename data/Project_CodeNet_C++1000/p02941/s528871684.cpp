#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const ll mod = 7*17*(1<<23) + 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n, a[200100], b[200100];
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	priority_queue<pair<int, int>> q;
	for(int i = 1; i <= n; i++) {
		if(b[i]<a[i])return cout << -1, 0;
		if(b[i]>a[i]) q.push({b[i], i});
	}
	b[0]=b[n], b[n+1]=b[1];
	ll ans = 0;
	while(!q.empty()) {
		int i, v;
		tie(v,i) = q.top(), q.pop();
//		cout << i << " " << v << "\n";
		int t = b[i]%(b[i-1]+b[i+1]);
//		cout << i << " " << t << "\n";
		ans += b[i]/(b[i-1]+b[i+1]);
		if(t < a[i]) {
			if((a[i]-t)%(b[i-1]+b[i+1])) return cout << -1, 0;
			ans -= (a[i]-t)/(b[i-1]+b[i+1]);
			t = a[i];
		} else if(b[i]/(b[i-1]+b[i+1]) == 0)
			return cout << -1, 0;
		b[i] =t;
		if(i==1)b[n+1]=b[1];
		if(i==n)b[0]=b[n];
//		cout << i << " " << t << "\n";
		if(t>a[i])
			q.push({b[i], i});
	}
	cout << ans << "\n";
	return 0;
}
