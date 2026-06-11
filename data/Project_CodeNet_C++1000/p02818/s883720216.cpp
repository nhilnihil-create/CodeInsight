#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    long long int a,b,k;
	cin>>a>>b>>k;
	if(k>0 && k>=a)
	{
		k-=a;
		a=0;
	}
	else
    {
      a-=k;
      k=0;
    }
	if(k>0 && k>=b)
	{
		k-=b;
		b=0;
	}
	else
	b-=k;
	printf("%lld %lld",a,b);
}