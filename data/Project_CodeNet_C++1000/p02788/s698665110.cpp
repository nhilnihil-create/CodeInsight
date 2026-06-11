#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = (ll)1<<62;
const ll MOD = 1e9+7;

int main(){
	int n, last_id;
	ll d, a, diff;
	vector<pair<ll, ll> > v;
	vector<ll> dec;
	cin>>n>>d>>a;
	v.assign(n, {0, 0});
	dec.assign(n, 0);
	for(int i=0;i<n;i++)
		cin>>v[i].first>>v[i].second;
	sort(v.begin(), v.end());
	ll ans = 0;
	ll t_diff = 0;
	int i = 0;
	while(i<n){
		ll spos = v[i].first+d;
		ll epos = spos+d;

		last_id = upper_bound(v.begin(), v.end(), make_pair(v[i].first-2*d, (ll)-1))-v.begin();
		if(last_id==0)
			diff = t_diff;
		else
			diff = t_diff-dec[last_id-1];

		ll num = (v[i].second-diff+a-1)/a;
		t_diff += a*num;
		ans += num;
		
		int j = i;
		while(j<n){
			if(v[j].first > epos)
				break;
			
			last_id = upper_bound(v.begin(), v.end(), make_pair(v[j].first-2*d, (ll)-1))-v.begin();
			if(last_id == 0)
				diff = t_diff;
			else
				diff = t_diff-dec[last_id-1];
			
			if(diff>=v[j].second){
				dec[j++] = t_diff;
			}
			else
				break;

		}
		i = j;
	}
	cout<<ans<<"\n";
	return 0;
}