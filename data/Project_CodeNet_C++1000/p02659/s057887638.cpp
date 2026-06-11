#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;

int main()
{
	ll n,a;
	ld b;
	cin>>a>>b;
	n=round(b*100);
	cout<<fixed<<setprecision(0)<<(a*n)/100<<endl;
	return 0;
}