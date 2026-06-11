#include <iostream>

using namespace std;

int main(){

	long long int n,a,b;
	cin>>n>>a>>b;
	long long int x=n/(a+b);
	long long int ans=x*a;
	x*=(a+b);
	if(x+a<=n){
	
		ans+=a;
	}
	else{
	
		ans+=a;
		x+=a;
		ans-=(x-n);
	}
	cout<<ans<<'\n';
	return 0;
}
