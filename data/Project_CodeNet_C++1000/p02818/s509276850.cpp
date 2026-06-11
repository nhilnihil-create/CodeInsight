//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	
	ll a,b,c;
	cin>>a>>b>>c;

	ll t = max(0LL, a-c);
	c = max(0LL,c - a);
	//cout<<c<<endl;
	ll aa = max(0LL, b-c);

	cout<<t<<" "<<aa<<endl;

	

	return 0;
}