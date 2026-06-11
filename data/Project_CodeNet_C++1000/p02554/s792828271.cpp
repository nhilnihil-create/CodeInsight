#include <bits/stdc++.h>
using namespace std;
long long n,x=1,y=1,z=1,i;
int main()
{
	cin >> n;
	for (i=1; i<=n; i++)
	x=(x*10)%1000000007;
	
	for (i=1; i<=n; i++)
	y=(y*9)%1000000007;
	
	for (i=1; i<=n; i++)
	z=(z*8)%1000000007;
	if (x-y-y+z<-1000000007)
	cout<<x-y-y+z+2*1000000007;
	else
	if (x-y-y+z<0)
	cout<<x-y-y+z+1000000007;
	else
	cout<<x-y-y+z;

}