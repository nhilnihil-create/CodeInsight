#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main(int argc, char const *argv[])
{
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll m = max(a*c,a*d);
	ll m2 = max(b*c,b*d);
	m = max(m,m2);
	cout<<m<<endl;	
	return 0;
}