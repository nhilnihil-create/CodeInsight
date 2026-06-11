#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	fastio
	ll n;
	cin>>n;
	ll cnt=1,ans=0;
	while(n>0){
		ans+=cnt;
		cnt*=2;
		n/=2;
	}
	cout<<ans;
	return 0;
}