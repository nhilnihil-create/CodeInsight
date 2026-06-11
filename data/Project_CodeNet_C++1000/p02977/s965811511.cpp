//Love and Freedom.
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 20021225
#define id(x) (x>n?x-n:x)
#define N 400100
using namespace std;
int read()
{
	int s=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return f*s;
}
void e(int x,int y){printf("%d %d\n",x,y==2?3:y);} 
int main()
{
	int n=read();// int lg=log(n)/log(2.0);
	if((n&-n)==n)	return puts("No"),0;
	puts("Yes");
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
	int top=n-1;
	for(int i=4;i<=top;i+=2)	e(i,1),e(i+1,i),e(n+i+1,1),e(n+i,n+i+1);
	if(!(n&1))
	{
		int x=n+1;
		for(int i=1;i<=20;i++)
			if(x&(1<<i))
			{
				int X=1<<i,Y=x-X;
				e(X,n),e(Y+n,n<<1);
				return 0;
			}
	}
	return 0;
}