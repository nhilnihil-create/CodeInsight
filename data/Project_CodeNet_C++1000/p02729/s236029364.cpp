#include<stdio.h>
int main(){
	int n,m;   // n even m odd
	int sum1=0;
	int sum2=0; 
	scanf("%d %d",&n,&m);
	
	if(n>1){
		for(int i=1;i<n;i++){
			sum1+=i;
		}
	}
	if(m>1){
		for(int i=1;i<m;i++){
			sum2+=i;
		}
	}
	printf("%d", sum1+sum2);
	return 0;
}