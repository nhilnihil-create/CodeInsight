#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	if(a%b==0)return b;
	else return gcd(b,a%b);
}
void solve(){
	ll a,b,tmp;
	int ans=0;
	scanf("%lld %lld",&a,&b);
	tmp=gcd(a,b);
	for(ll i=2;i*i<=tmp;i++){
		if(tmp%i==0){
			ans++;
			while(tmp%i==0)tmp/=i;
		}
	}
	if(tmp>1)ans++;
	printf("%d",ans+1);
}
signed main(){
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}