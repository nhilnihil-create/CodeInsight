#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int n,p[N];

void task0()
{
	p[1]=n&(-n),p[2]=n^p[1];
	int tot=2;
	rep(i,1,n-1) if(i!=p[1] && i!=p[2]) p[++tot]=i;
	rep(i,1,tot-1) printf("%d %d\n",p[i],p[i+1]);
	printf("%d %d\n",p[tot],p[1]+n);
	rep(i,1,tot-1) printf("%d %d\n",p[i]+n,p[i+1]+n);
	printf("%d %d\n",p[1],n);
	printf("%d %d\n",p[2],2*n);
}

void task1()
{
	rep(i,1,n-1) p[i]=i+1;
	rep(i,1,n-2) printf("%d %d\n",p[i],p[i+1]);
	printf("%d %d\n",p[n-1],p[1]+n);
	rep(i,1,n-2) printf("%d %d\n",p[i]+n,p[i+1]+n);
	printf("%d %d\n",p[1],1);
	printf("%d %d\n",p[2],n+1);
}

void task2()
{
	p[2]=n&(-n),p[1]=p[2]+1,p[3]=n^p[2];
	int tot=3;
	rep(i,2,n-1) if(i!=p[1] && i!=p[2] && i!=p[3]) p[++tot]=i;
	rep(i,1,tot-1) printf("%d %d\n",p[i],p[i+1]);
	printf("%d %d\n",p[tot],p[1]+n);
	rep(i,1,tot-1) printf("%d %d\n",p[i]+n,p[i+1]+n);
	printf("%d %d\n",p[1],1);
	printf("%d %d\n",p[2],n+1);
	printf("%d %d\n",p[2],n);
	printf("%d %d\n",p[3],2*n);
}

void task3()
{
	rep(i,1,2*n-1) printf("%d %d\n",i,i+1);
}

int main()
{
	scanf("%d",&n);
	if(n==(n&(-n))) return puts("No"),0;
	puts("Yes");
	if(n%4==0) task0();
	if(n%4==1) task1();
	if(n%4==2) task2();
	if(n%4==3) task3();
	return 0;
}