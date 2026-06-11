#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
#include<set> 
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;
const int maxn = 1e3 + 5;
const int p = 233;
typedef unsigned long long ull;
int main()
{
	int n,sum1=0,sum2=0,cnt1=0,cnt2=0,flag1=0,flag2=0;
	int a[9],b[9],c[9],d[9];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		d[i]=b[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1); 
	do{
		cnt1++;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==c[i])
				flag1++;
		}
		if(flag1==n)
			break;
		flag1=0;
	}while(next_permutation(a+1,a+n+1));
	do{
		cnt2++;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==d[i])
				flag2++;
		}
		if(flag2==n)
			break;
		flag2=0;
	}while(next_permutation(b+1,b+n+1));
	int res=cnt2-cnt1;
	if(res>=0)
		cout<<res;
	else
		{
			res=-res;
			cout<<res;
		}	
}