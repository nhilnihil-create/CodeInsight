#include<cstdio>
#define ri register int
#define rc register char
#define ll long long int
#define rl register long long int
#define in inline
#define gc getchar
in int read()
{
	ri x=0,p=1;
	rc ch=gc();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		{
			p=-1;
		}
		ch=gc();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+ch-'0',ch=gc();
	}
	return x*p;
}
int a[100]={0,1,1,1,2,1,2,1,5,2,2,1,5,1,2,1,14,1,5,1,5,2,2,1,15,2,2,5,4,1,4,1,51};
int main()
{
	ri k=read();
	printf("%d\n",a[k]);
}