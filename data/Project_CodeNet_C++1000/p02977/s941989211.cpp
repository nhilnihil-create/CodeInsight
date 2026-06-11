#include<bits/stdc++.h>
using namespace std;
int pw=1,n;

int main(){
	scanf("%d",&n);
	while(pw<n) pw*=2;
	if(pw==n){puts("No");return 0;}
	puts("Yes");
	if(n==pw-1){
		for(int i=1;i<2*n;i++) printf("%d %d\n",i,i+1);
		return 0;
	}
	printf("2 3\n");
	printf("3 1\n");
	printf("1 %d\n",n+2);
	printf("%d %d\n",n+2,n+3);
	pw=8;
	while(pw-1<=n){
		for(int i=pw/2;i<pw-1;i++) printf("%d %d\n",i,i+1);
		printf("%d %d\n",pw-1,n+pw/2);
		for(int i=pw/2;i<pw-1;i++) printf("%d %d\n",n+i,n+i+1);
		pw*=2;
	}
	pw/=2;
	printf("%d %d\n",n+1,pw);
	printf("%d %d\n",pw,pw+1);
	printf("%d 1\n",pw+1);
	printf("1 %d\n",n+pw);
	printf("%d %d\n",n+pw,n+pw+1);
	for(int i=pw+2;i+1<=n;i+=2){
		printf("%d %d\n",i,i+1);
		printf("%d 1\n",i+1);
		printf("1 %d\n",n+i);
		printf("%d %d\n",n+i,n+i+1);
	}
	if(n%2==1){
		for(int i=4;i<=pw/2;i*=2) printf("1 %d\n",i);
		return 0;
	}
	else{
		int at;
		if(n&2) printf("%d %d\n",n,n+2),at=pw+1;
		else printf("%d %d\n",n,pw),at=pw;
		for(int i=4;i<=pw/2;i*=2){
			if(n&i) printf("%d %d\n",at,i),at=i;
			else printf("1 %d\n",i);		
		}
		printf("%d %d\n",at,2*n);
	}
	
	return 0;
}