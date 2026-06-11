#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll LCD(ll a,ll b){
	if(a<b) swap(a,b);
	while(b){
		ll t = a%b;
		a = b;
		b = t;
	}
	return a;
}
ll solve(ll a,ll b){ //number of multiples of b before a
	return a/b;
}
int main(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll lcm = c*(d/LCD(c,d));
	ll ret = 0;
	ret+=(solve(b,c)-solve(a-1,c));
	ret+=(solve(b,d)-solve(a-1,d));
	ret-=(solve(b,lcm)-solve(a-1,lcm));
	cout<<b-a+1-ret;
}