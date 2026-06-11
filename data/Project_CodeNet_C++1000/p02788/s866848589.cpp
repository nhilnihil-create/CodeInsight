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
	vii monster(n);
	vll c(n+1);
	for(int i=0;i<n;++i){
		cin>>monster[i].ff >> monster[i].ss;
	}
	sort(all(monster));
	for(int i=0,j=0;i<n;++i){
		while(j<n&&monster[j].ff<=monster[i].ff+2*d)
			++j;
		ll need = max((monster[i].ss-c[i]*a+a-1)/a,0LL);
		c[i]+=need;
		c[j]-=need;
		ans+=need;
		c[i+1]+=c[i];
	}
	cout<<ans<<endl;
	return 0;
}
