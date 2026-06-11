#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,N;
int main()
{
    n=read();
    if(n<=2) return 0*puts("No");
    for(N=1;N<=n+1;N<<=1);N>>=1;
    if(N==n) return 0*puts("No");puts("Yes");--N;
    for(int i=1;i<N;++i) printf("%d %d\n",i,i+1),printf("%d %d\n",i+n,i+n+1);
    printf("%d %d\n",N,n+1);
    if((n-N)%2==0)
    {
        for(int i=1;i<=n-N;i+=2)
            printf("%d 1\n%d 1\n",N+i,N+i+1),
            printf("%d %d\n%d %d\n",N+i+n,N+i+1,N+i+1+n,N+i);
        return 0;
    }
    else
    {
        for(int i=1;i<=n-N;i+=2+(i==1))
            printf("%d %d\n%d %d\n",N+i,(i-1)^i,N+i+1,(i-1)^i),
            printf("%d %d\n%d %d\n",N+i+n,N+i+1,N+i+1+n,N+i);
        printf("%d 2\n%d %d\n",N+3,N+2,N+3+n);
    }
	return 0;
}
