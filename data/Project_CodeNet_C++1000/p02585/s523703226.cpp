#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 5e3+5;
const ll mod =   1e9+7;
ll n,k;ll ans=-1e18;
ll a1[N],a2[N];
bool bo[N];
void solve(int idx){
	memset(bo,false,sizeof bo);
	ll x=0;vector<ll> v(5005);
	while(!bo[idx]){
		v[++x]=a2[idx];
		bo[idx]=true;
		idx=a1[idx];
	}
	for(int i=2;i<=x;i++)
	v[i]+=v[i-1];
	ll an=-1e18;
	for(int i=1;i<=min(x,k);i++)
	{
		an=max(an,v[i]);
		an=max(an,v[i]+(k-i)/x*v[x]);
	}
	ans=max(ans,an);
	
}
int main()
{  fast
cin>>n>>k;
for(int i=1;i<=n;i++)
cin>>a1[i];
for(int i=1;i<=n;i++)
cin>>a2[i];
for(int i=1;i<=n;i++)
solve(i);
cout<<ans;
}