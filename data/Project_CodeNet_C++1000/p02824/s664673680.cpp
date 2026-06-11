//CF handle :dineshg
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pll pair<ll,ll>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

ll n,m,v,p;
ll arr[100007];
ll faltu;
ll fi;

bool fun(ll x)
{
	ll tot = m*v;
	ll curr = (p)*m;
	curr+= (n-x)*m;

	if(curr >= tot)
		return 1;
	for(ll i=p;i<x ;i++)
	{
		//if(i!=x){
		if(arr[x] - arr[i] + m >=0)
			curr+=arr[x]-arr[i]+m;
		if(curr>=tot)
			return 1;
	//}
	}

	return 0;

}
int main()
{
	fastio
	cin >> n >> m >> v >>p;
	for(ll i=1;i<=n;i++)
		cin >> arr[i];
	sort(arr+1,arr+n+1 ,greater<int>());
	ll i;
	for( i=p+1;i<=n;i++)
	{
		if(arr[i]+m <arr[p])
			break;
	}
	ll start = p;
	ll end = i-1;

	fi = i;
	faltu = n-i+1;

	ll mid = start + (end-start)/2;
//	cout << start << " " << mid << " " << end << endl;
	while(end-start>1)
	{
		if(fun(mid))
			start =mid;
		else
			end=mid-1;

		mid = start + (end-start)/2;


	//cout << start << " " << mid << " " << end << endl;
	}
	ll ans;
	for(ll i= start ;i<=min(n,end);i++)
	{
		if(fun(i)){
	//		cout << i << endl;
			ans = i;
		}
	}
//	cout << fun(2);
	cout << ans << endl;

	return 0;	
}
