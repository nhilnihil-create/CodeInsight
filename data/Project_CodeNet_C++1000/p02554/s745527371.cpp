int power(long long x, unsigned int y, int p )
{
	int ans=1;
	x=x%p;
	if(x==0) return 0;

	while(y>0)
	{
		if(y%2)
			ans=(ans*x)%p;
	
		y=y/2;
		x=(x*x)%p;
	}
	return ans;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
 	int n;
  cin>>n;
  int x=1000000007;
  long a=((power(10,n,x)%x-(2%x)*(power(9,n,x))%x)+x)%x;
  long b=(a%x+1ll*power(8,n,x)%x)%x;
  cout<<b;
return 0;
}