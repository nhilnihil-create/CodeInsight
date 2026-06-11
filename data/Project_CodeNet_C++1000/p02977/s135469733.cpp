#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
using namespace std;
int n;
void p(int x,int y){printf("%d %d\n",x,y);}
int main(){
	cin>>n;
	if(n<=2)return printf("No"),0;
	if(n&1){
		printf("Yes\n");
		p(1,2);
		p(2,3);
		p(3,n+1);
		p(n+1,n+2);
		p(n+2,n+3);
		for(int i=4;i<=n;i+=2)
			p(1,i),p(i,i+1),p(n+1,n+i+1),p(n+i+1,n+i);
		return 0;
	}
	int k=1;
	for(;1<<k+1<=n;++k);
	if(1<<k==n)return printf("No"),0;
	printf("Yes\n");
	int a=n^(n-1)^1;
	p(1,2);
	p(2,3);
	p(3,n+1);
	p(n+1,n+2);
	p(n+2,n+3);
	for(int i=4;i<n;i+=2)
		if(i==n-2)p(1,i+1),p(i+1,i),p(n+1,n+i),p(n+i,n+i+1);
		else p(1,i),p(i,i+1),p(n+1,n+i+1),p(n+i+1,n+i);
	p(n,n-1);
	p(n+n,a);
}