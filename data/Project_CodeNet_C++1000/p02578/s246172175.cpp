#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void)
{
	long long i,n,a[200000],m,sum;
	scanf("%lld",&n);
	for(i=0;i<n;i++)	scanf("%lld",&a[i]);
	m=a[0];	sum=0;
	for(i=1;i<n;i++){
		if(a[i]>=m)	m=a[i];
		else	sum+=m-a[i];
	}
	printf("%lld\n",sum);
	return 0;
}
