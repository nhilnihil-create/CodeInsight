#include<cstdio>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;
int main(void)
{
	long long n,x;
	int i,a,b[100];
	char c;
	scanf("%lld",&n);
	n--;
	x=26;
	a=1;
	while(1)	{
		if(n<x)	{
			for(i=0;i<a;i++)	{
				b[i]=n%26;
				n=n/26;
			}
			for(i=a-1;i>=0;i--)	{
				c='a'+b[i];
				printf("%c",c);
			}
			printf("\n");
			break;
		}
		else{
			n-=x;
			x=x*26;
			a++;
		}
	}
	return 0;
}