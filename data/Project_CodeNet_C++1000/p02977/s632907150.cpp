#include <bits/stdc++.h>
int n;
int lowbit(int x){
	return (x) &(-x);
}
int main(){
	scanf("%d",&n);
	int t=__builtin_popcount(n);
	if (t==1){
		puts("No");
		return 0;
	} 
	puts("Yes\n1 3\n3 2");
	printf("2 %d\n",1+n);
	printf("%d %d\n",1+n,3+n);
	printf("%d %d\n",n+2,n+3);
	for (int i=4;i<=((n-1)/2)*2+1;i+=2){
		printf("%d 1\n",i+1);
		printf("%d 1\n",i);
		printf("%d %d\n",i,i+1+n);
		printf("%d %d\n",i+n,i+1);
	}
	if (n%2==0){
		int x=lowbit(n),y=n^x;
		printf("%d %d\n",y,n);
		printf("%d %d\n",n+n,x+1);
	}
}