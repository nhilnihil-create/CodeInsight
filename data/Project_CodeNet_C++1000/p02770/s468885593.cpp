#include<bits/stdc++.h>
using namespace std;
int d[5005],zero[5005];//zero[i]累计di=0个数 
long long a[5005];//a[i]累计d 
int main()
{
	int k,q;scanf("%d%d",&k,&q);
	for(int i=0;i<k;++i)
	scanf("%d",&d[i]);
	while(q--)
	{
		int n,x,m,sum,sumzero,sumn;
		scanf("%d%d%d",&n,&x,&m);
		x%=m;a[0]=0;zero[0]=0; 
		for(int i=0;i<k;++i)
		{
			a[i+1]=a[i]+d[i]%m;
			zero[i+1]=zero[i]+(d[i]%m==0); 
		}//以k为一个循环重复累加 
		sumzero=(n-1)/k*zero[k]+zero[(n-1)%k];//共有(n-1)/k次d的循环加上剩下的(n-1)%k
		sum=((n-1)/k*a[k]+a[(n-1)%k]+x)/m-x/m;
		sumn=(n-1)-sum-sumzero;
		printf("%d\n",sumn); 
	}
}