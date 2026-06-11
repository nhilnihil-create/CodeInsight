#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,i,j,a,b,c,d,ara[4];
	cin>>a>>b>>c>>d;
	ara[0]=a*c;
	ara[1]=a*d;
	ara[2]=b*c;
	ara[3]=b*d;
	sort(ara,ara+4);
	cout<<ara[3]<<'\n';
	return 0;
}