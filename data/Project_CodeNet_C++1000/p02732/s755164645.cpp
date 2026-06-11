#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
int main(){
    int n; cin>>n;
    ll a[n],s,ans;
    map<ll,ll> mp;
    rep(i,n) cin>>a[i],mp[a[i]]++;
    s=0;
    for(auto p:mp) {auto v=p.second;s+=v*(v-1)/2;}
    rep(i,n){
    	ans=s;
    	ans-=mp[a[i]]*(mp[a[i]]-1)/2;
    	ans+=(mp[a[i]]-1)*(mp[a[i]]-2)/2;
    	cout<<ans<<endl;
	}


}
