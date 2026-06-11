#include<iostream>
using namespace std;
#define ll long long int


int main()
{
	ll a,b,k;
	cin>>a>>b>>k;
	if(a>=k) cout<<a-k<<' '<<b;
	else {
		ll x=k-a;
		if(x>=b) cout<<"0 0";
		else cout<<'0'<<' '<<b-x;
	}
	cout<<endl;
	return 0;
}