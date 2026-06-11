#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265358979
#define EPS 1e-8
#define mod  998244353
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define NEG_INF -2e18
			 
const ll INF=1e15;	
const int N=2e5+50;
		 
 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(0);
		
	ll n;
	cin>>n;
	ll ans=0;
	for(ll i=1;i<n;i++)
	{
		ans+=(n-1)/i;
	}
	cout<<ans;
}
