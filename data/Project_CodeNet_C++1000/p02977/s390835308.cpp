#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,k=1;
void link(int a,int b){printf("%d %d\n",a,b);}
int main()
{
	scanf("%d",&n);while(k<n) k=k*2;
	if(k==n){puts("No");return 0;}
	puts("Yes");link(n+1,n+2);link(n+2,n+3);link(n+3,1);
	link(1,2);link(2,3);int tn=n;if(n%2==0) n--;
	for(int i=4;i<=n;i+=2){
		link(i,i+1);link(i+tn,i+tn+1);
		link(i,1);link(i+tn+1,1);
	}
	if(tn%2==0){
		for(int i=2;i<tn;i+=2){
			int tmp=(tn^1^i);
			if(tmp>1&&tmp<tn){link(tmp+tn,tn);link(i,2*tn);break;}
		}
	}
	return 0;
}