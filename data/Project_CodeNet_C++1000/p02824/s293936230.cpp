#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll w[200500], n, m, v, p;
inline bool check(ll e)
{
	if (e >= n-p) return true;
	ll t = (p-1)*m;
	for(ll i = 0; i+p <= n; i++)
	{
		if (min(m, w[e]+m-w[i]) < 0) return false;
		t+=min(m, w[e]+m-w[i]);
	}
	return t >= m*v;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>v>>p;
	for(int i = 0; i < n; i++) cin>>w[i];
	sort(w, w+n);
	ll cnt = 0, l = -1, r = n;
	while(r-l > 1)
	{
		int mid = (l+r)/2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	cout<<n-r;
	return 0;
}
