#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[114514];
int main(){
	ll n;
	cin>>n;
	map<ll,ll>mp;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	if(mp[0]==n)cout<<"Yes";
	else if(n%3)cout<<"No";
	else{
		sort(a,a+n);
		if((mp[0]==n/3&&mp[a[n/3]]==2*n/3)||(mp[a[0]]==n/3&&mp[a[n/3]]==n/3&&mp[a[2*n/3]]==n/3&&((a[0]^a[n/3]^a[2*n/3])==0)))cout<<"Yes";
		else cout<<"No";
	}
	return 0;
}
