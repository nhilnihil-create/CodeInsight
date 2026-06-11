#include<bits/stdc++.h>
#include<iomanip>
#define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define N 1000000
#define ar array
#define mod 1000000007
#define ld long double
#define pb push_back
#define f first
#define s second
typedef long long int ll;
using namespace std;
int main(void){
	#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	fast;
	ll n,k,ans=0,i;
	cin>>n>>k;
	ll p[n+2]={0};
	ll s[n+2]={0};
	p[1]=0;
	s[n+1]=n;
	for(i=2;i<=n+1;i++){
		p[i]=p[i-1]+i-1;
		p[i]%=mod;
	}
	for(i=n-1;i>=0;i--){
		s[i+1]=s[i+2]+i;
		s[i]%=mod;
	} 
	for(i=k;i<=n+1;i++){
		if(s[n-i+2]>=p[i])
		ans+=s[n-i+2]-p[i]+1;
		ans%=mod;
	}
	cout<<ans;
}
