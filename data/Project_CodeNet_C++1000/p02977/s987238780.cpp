#include<bits/stdc++.h>
using namespace std;
void P(int x,int y){printf("%d %d\n",x,y);}
int main(){
	int n;
	scanf("%d",&n);
	int N=n;
	while(N%2==0)N/=2;
	if(N==1){printf("No");return 0;}
	printf("Yes\n");
	P(1,2);P(2,3);P(3,1+n);P(1+n,2+n);P(2+n,3+n);
	if(n==3)return 0;
	for(int i=4,ls=1;i<=n;i+=4){
		if(i+4>n+1)break;
		if(n&3)P(i,i-ls);
		P(i,i+1);P(i+1,i+2);P(i+2,i+3);
		P(i+3,i+n);P(i+n,i+n+1);P(i+n+1,i+n+2);P(i+n+2,i+n+3);
		ls=i;
	}
	if(n%4==0){
		int ls=0;
		for(int t=4,i=4;i<n;i+=4){
			if(t+t==i)t=t+t;
			if(i==t&&(n&t)){
				if(ls)P(i,ls);else{
					P(i,n);P(i,i==4?1:i-4);
				}
				ls=t;
			}else P(i,i==4?1:i-4);
		}P(ls,n+n);
	}else
	if(n%4==1){
		P(1,n);P(n,n-1);
		P(1,n+n-1);P(n+n-1,n+n);
	}else
	if(n%4==2){
		P(3,n);P(n,n-1);
		P(3,n+n-1);P(n+n-1,n+n);
		P(1+n,n-2);P(n,n+n-2);
	}
}