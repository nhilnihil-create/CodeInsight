#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if((n&-n)==n)	puts("No");
	else{
		puts("Yes");
		for(int i=3;i<=n;i+=2){
			printf("%d %d\n",1,i-1);
			printf("%d %d\n",1,i+n);
			printf("%d %d\n",i-1,i);
			printf("%d %d\n",i+n,i+n-1);
		}
		printf("%d %d\n",n+1,3);
		if(n%2==0){
			int k=n&-n;
			printf("%d %d\n",n,k);
			printf("%d %d\n",n+n,(n-k+1)+n);
		}
	}
	return 0;
}
