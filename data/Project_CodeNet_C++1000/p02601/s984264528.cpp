#include<bits/stdc++.h>
#define fint register int
#define h 5001
#define p 7659834
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;//aim:c>b>a;
	int k;
	cin>>k;
	int ans=0;
	while(a>=b)
	b*=2,ans++;
	while(b>=c)
	c*=2,ans++;
	if(ans<=k)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}