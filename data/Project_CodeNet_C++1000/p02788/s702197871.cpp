#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2e5+10;
int N, D, A;
pair<ll,ll> v[MAX_N];
ll damage[MAX_N];

void solve()
{
	sort(v,v+N);
	ll ans = 0;
	for(int i=0;i<N;++i){
		if(i>0) damage[i]+=damage[i-1];
		if(damage[i]>=v[i].second) continue;
		const ll b = 1LL*(v[i].second-damage[i]+A-1)/A;
		ans += b;
		int j = upper_bound(v, v+N, make_pair(v[i].first+2LL*D,1LL<<60))-v;
		damage[i]+=b*A, damage[j]-=b*A;
	}
	cout<<ans;
}

int main()
{
	cin >> N >> D >> A;
	for(int i=0;i<N;++i) cin >> v[i].first >> v[i].second;
	solve();
	return 0;
}