#include<bits/stdc++.h>
using namespace std;
int n;
inline void addedge(int a,int b){printf("%d %d\n",a,b);}
int main()
{
	scanf("%d",&n);
	int vvv=1;
	while(vvv<n) vvv<<=1;
	if(vvv==n) return puts("No"),0;
	puts("Yes");
	for(int i=3;i<=n;i+=2)
	{
		addedge(1,i-1);addedge(i-1,i);
		addedge(1,n+i);addedge(n+i,n+i-1);
	}
	addedge(3,1+n);
	if(n%2==0)
	{
		int va=1;
		while((n&va)==0) va<<=1;
		addedge(n,va);
		addedge(n+n,(va^n^1)+n);
	}
}