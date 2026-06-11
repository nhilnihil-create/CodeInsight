#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	long int a[85];
	for(int i=0;i<n;i++){
		scanf("%ld",&a[i]);
	}
	long int s=1000;
	for(int i=0;i<n-1;i++){
		if(a[i+1]>a[i]){
			long int x;
			x=s/a[i];
			s=s%a[i]+x*a[i+1];
		}
	}
	printf("%ld",s);
}