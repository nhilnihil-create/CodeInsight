#include<iostream>
using namespace std;
long long ans=0;
int mod=1e9+7;
long long a[2010];
int main()
{
	int n;
	scanf("%d",&n);
	if(n<3)
	{
		cout<<"0"<<endl;
		return 0;
	}
	a[3]=1;
	for(int i=4;i<=n;i++)
	{
		a[i]=((a[i-1]%mod)+(a[i-3]%mod))%mod;
	}
	printf("%lld\n",a[n]);
}
/*
0 1
0 2
1 3
1 4
1 5
2 6
3 7
4 8
6 9
9 10
*/