
#include <bits/stdc++.h>
using namespace std;


#define M 1000000007
#define pb push_back
#define mp make_pair
#define s second
#define f first
#define mod 998244353
#define sz(v) (int)(v).size()

#define pii pair<int, int>
#define vi vector<int>
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)

ll add(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a+b)%M;
	return (p+M)%M;
}

ll mul(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a*b)%M;
	return (p+M)%M;
}


int main()
{
	fastio;
	ll i,j,k,n,a[200010];
	cin>>k>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	ll ma=-1e9;
	for(i=0;i<n-1;i++)
		ma=max(ma,a[i+1]-a[i]);
	ma=max(ma,a[0]+k-a[n-1]);
	cout<<k-ma<<endl;
    return 0;
}



