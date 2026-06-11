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
	int n;cin>>n;
	string s;cin>>s;
	int ans=1;
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1])ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
