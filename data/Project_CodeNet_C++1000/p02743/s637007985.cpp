#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,c;
	cin>>a>>b>>c;
	ll var1=c-a-b;
	if(var1<=0)
	 cout<<"No";
	else{
		ll var2=4*a*b;
		if(var1*var1>var2)
		 cout<<"Yes";
		else
		 cout<<"No";
	}
	return 0;
}