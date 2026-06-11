#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
	ll a, b, c, z;
	cin>>a>>b>>c;
	z = min(b-1 , c);
	cout<<floor(a*z/b)-a*(z/b)<<endl;
	return 0;
}