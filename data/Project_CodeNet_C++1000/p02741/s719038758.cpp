#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mod 1000000007
#define all(x) x.begin(),x.end()
typedef vector<ll> vll;
vll prime;
vector<pair<ll,ll> > Pair(100001);
ll modpower(ll a,ll b,ll c)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
			res=(res*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return res;
}
int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	ll t=1;
//	cin>>t;
	while(t--)
	{
	    int a[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	    int k;
	    cin>>k;
	    cout<<a[k-1]<<endl;
	    
		
	}
	return 0;
}


