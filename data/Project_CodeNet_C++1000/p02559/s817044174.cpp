#include <bits/stdc++.h>
using namespace std;
#define w(x) int x;cin>>x;while(x--)
#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define vi vector<int>
#define fr(a,b) for(int i=a;i<=b;i++)
#define inf 1e18
#define mod 1000000007
ll BIT[500005];
ll n;
ll answer(ll i)
{
	ll sum=0;
	while(i>0)
	{
		sum+=BIT[i];
		i=i-(i&(-i));
	}
	return sum;
}
void update(int i,ll val)
{
	while(i<=n)
	{
		BIT[i]+=val;
		i=i+(i&(-i));
	}
}
int main()
{   
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
#endif*/
	fast;
	ll q;
	cin>>n>>q;
	ll a[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(i,a[i]);
	}
	while(q--)
	{
		int k;
		cin>>k;
		if(k==0)
		{
			ll i,val;
			cin>>i>>val;
			update(i+1,val);
		}
		if(k==1)
		{
			int l,r;
			cin>>l>>r;
			cout<<answer(r)-answer(l)<<"\n";
		}
	}
    return 0;
}