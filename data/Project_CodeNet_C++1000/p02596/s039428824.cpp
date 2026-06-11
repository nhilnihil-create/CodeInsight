//I didn't solve this by my own
#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){

	while(b>0){
	
		a%=b;
		ll c=a;
		a=b;
		b=c;
	}
	return a;
}
int main(){

	int k;
	cin>>k;
	if(k%7==0){
	
		k/=7;
	}
	if(gcd(k,10)!=1){
	
		cout<<-1<<"\n";
		return 0;
	}
	ll v=1%k;
	ll ans=1;
	while(v!=0){
	
		v=(v*10+1)%k;
		ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
