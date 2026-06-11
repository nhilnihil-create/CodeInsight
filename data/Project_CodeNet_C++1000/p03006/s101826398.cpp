#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

int main()
{
	int n; cin>>n;

	vector<pii> p(n);
	map<pii,int> mp;
	for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++) {
			mp[make_pair(p[i].first-p[j].first,p[i].second-p[j].second)]++;
			mp[make_pair(p[j].first-p[i].first,p[j].second-p[i].second)]++;
		}
	}
	int ans=0;
	for(auto t:mp) {
		ans = max(ans,t.second);
	}

	cout<<n-ans;	
}