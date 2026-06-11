#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int a,b,c,k,flag=0;
	cin>>a>>b>>c>>k;
		while(b<=a)
		{
			b*=2;
			flag++;
		}
		while(c<=b)
		{
			c*=2;
			flag++;
		}
	if(flag<=k)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}