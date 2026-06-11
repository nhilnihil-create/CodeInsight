#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=100005;
int n,flag,a[N];
int main()
{
	scanf("%d",&n);
	for(int i=0; i<20; i++) if((1<<i)==n) flag=1;
	if(flag){puts("No"); return 0;}
	puts("Yes");
	if(n%4==3){
		for(int i=1; i<2*n; i++) printf("%d %d\n",i,i+1);
		return 0;
	}
	else if(n%4==0){
		int x=n&(-n),y=n-x,len=2;
		a[1]=x; a[2]=y;
		for(int i=1; i<=n-1; i++) if(i!=x && i!=y) a[++len]=i;
		for(int i=1; i<n-1; i++) printf("%d %d\n",a[i],a[i+1]),printf("%d %d\n",a[i]+n,a[i+1]+n);
		printf("%d %d\n",a[n-1],a[1]+n);
		printf("%d %d\n%d %d\n",n,a[1],a[2],n+n);
	}
	else if(n%4==1){
		for(int i=1; i<n-2; i++) printf("%d %d\n",i,i+1),printf("%d %d\n",i+n,i+1+n);
		printf("%d %d\n",n-2,1+n);
		printf("%d %d\n%d %d\n",n,n-1,n-1,1);
		printf("%d %d\n%d %d\n",1,n+n,n+n,n-1+n);
	}
	else{
		int len=1; a[1]=3;
		for(int i=1; i<=n-3; i++) if(i!=3) a[++len]=i;
		for(int i=1; i<n-3; i++) printf("%d %d\n",a[i],a[i+1]),printf("%d %d\n",a[i]+n,a[i+1]+n);
		printf("%d %d\n",a[n-3],a[1]+n);
		printf("%d %d\n%d %d\n",n-1,n-2,n-2,1);
		printf("%d %d\n%d %d\n",1,n-1+n,n-1+n,n-2+n);
		printf("%d %d\n%d %d\n",n,3,n-2,n+n);
	}
	return 0;
}