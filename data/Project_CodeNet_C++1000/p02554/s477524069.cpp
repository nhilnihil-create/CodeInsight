#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int K=1000000007;
int n,ans;
int Pow(int A,int B)
{
	int res=1;
	while (B)
	{
		if (B&1) res=(LL)res*A%K;
		A=(LL)A*A%K;
		B>>=1;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	ans=(Pow(10,n)-Pow(9,n)*2ll+Pow(8,n)+K*2)%K;
	printf("%d\n",ans);
	return 0;
}
