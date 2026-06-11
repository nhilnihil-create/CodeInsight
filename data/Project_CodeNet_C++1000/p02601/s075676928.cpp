#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,k;
ll ans;
int main()
{
	int i,j,k;
	cin>>a>>b>>c>>k;
	//b>a;
	//c>b;
	while(b<=a)
	{
		b=b*2;
		ans++;
	}
	while(c<=b)
	{
		c=c*2;
		ans++;
	}
	if(ans<=k)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
	return 0;
}