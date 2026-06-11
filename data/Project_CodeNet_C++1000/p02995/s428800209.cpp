#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define ll long long
#define debug(x) cout<<x<<endl;
ll lcm(ll x,ll y){
	return x*y/(ll)(__gcd(x,y));
}
int main(){
	ll a,b,c,d; cin>>a>>b>>c>>d;
	ll tn=b-a+1;
	ll dc=b/c-(a-1)/c;
	ll dd=b/d-(a-1)/d;
	ll lc=lcm(c,d);
	ll dbc=b/(lc)-(a-1)/(lc);
	ll td=dd+dc-dbc;
/*	debug(tn);
	debug(dc);
	debug(dd);
	debug(dbc);
	debug(td);*/
	cout<<tn-td<<endl;
}
