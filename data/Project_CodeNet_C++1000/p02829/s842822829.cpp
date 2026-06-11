#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define ll long long
#define INF INT_MAX
#define mod 1000000007
#define chutiyaap ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
ll pw(ll a, ll b) {
    if (b == 0) return 1;
    ll t = pw(a, b / 2);
    if (b % 2 == 0) return (t * t)%mod;
    else return ((t * t)%mod * a)%mod;
}
int main()
{
	int a,b;cin>>a>>b;
	if(a*b==2)cout<<3;
	else if(a*b==6)cout<<1;
	else cout<<2;
}
