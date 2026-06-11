#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,d,a,ans=0;
	cin>>n>>d>>a;
	vii vs(n);
	for(int i=0;i<n;++i){
		cin>>vs[i].ff>>vs[i].ss;
	}
	sort(all(vs));
	ll s=0;
	queue<ii> q;
	for(int i=0;i<n;++i){
		while(!q.empty() && q.front().ff <vs[i].ff){
			s-=q.front().ss;q.pop();
		}
		vs[i].ss=max(0LL,vs[i].ss-s);
		ll k = (vs[i].ss+a-1)/a;
		ans+=k;
		s+=a*k;
		q.push({vs[i].ff+2*d,a*k});
	}
	cout<<ans<<endl;
	return 0;
}
