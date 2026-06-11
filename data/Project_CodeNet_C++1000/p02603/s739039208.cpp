#include<bits/stdc++.h>
using namespace std;
long long int num[1010];
int main()
{
	long long int n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
	{
        scanf("%lld",&num[i]);
    }
    long long int m=1000;
    for(int i=2;i<=n;i++)
	{
        if(num[i]>num[i-1]) 
			m=m%num[i-1]+(m/num[i-1])*num[i];
    }
    printf("%lld",m);
	return 0;
}














