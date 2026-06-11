#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll one=b*d;
	ll two=a*c;
	ll three=b*c;
	ll four=a*d;
	ll m1=max(one,two);
	ll m2=max(three,four);
	ll ans=max(m1,m2);
	cout<<ans<<endl;

}