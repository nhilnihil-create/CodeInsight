#include<bits/stdc++.h>
#define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define pb push_back
typedef long long int ll;
using namespace std;
int main(void){
	fast;
	ll n,ans=0,i,j;
	cin>>n;
	ll a[n];
	map<ll,ll>mp;
	for(i=0;i<n;i++){
	cin>>a[i];
	//mp[i+a[i]]++;
	mp[i+a[i]]++;
//	ans+=mp[i+a[i]]-1;
	//ans+=mp[i-a[i]];
	}
	for(j=1;j<n;j++)
	ans+=mp[j-a[j]];
	cout<<ans;
}
