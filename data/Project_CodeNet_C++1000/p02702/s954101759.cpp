#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=2019;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    ll n,ans=0,i,suf=0,p=1;
    cin>>s;
    n=s.length();
    vector<ll>mp(mod+3);
    mp[0]++;
    for(i=n-1;i>=0;i--){
    	int dig=s[i]-'0';
    	suf=((suf%mod)+((p*dig)%mod))%mod;
    	p=(p*10)%mod;
    	ans+=mp[suf];
    	mp[suf]++;
    }
    cout<<ans<<"\n";
}