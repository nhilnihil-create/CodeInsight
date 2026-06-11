#include<bits/stdc++.h>
int n,i,m;
int main(){
	scanf("%d",&n);for(m=1;m<n;m<<=1);
	if(m==n){
		puts("No");
		return 0;
	}
	m>>=1;
	puts("Yes");
	printf("%d %d\n",m,m+1);
	printf("%d %d\n",m+1,1);
	printf("%d %d\n",1,m+n);
	printf("%d %d\n",m+n,m+1+n);
	printf("%d %d\n",m+1+n,1+n);
	for(i=2;i<n;i+=2)if(i!=m){
		printf("%d %d\n",i,1);
		printf("%d %d\n",i+1,1);
		printf("%d %d\n",i+n,i+1);
		printf("%d %d\n",i,i+1+n);
	}
	if(i==n && i>m+1){
		printf("%d %d\n",i,m^i);
		printf("%d %d\n",i+n,m+1);
	}
	return 0;
}