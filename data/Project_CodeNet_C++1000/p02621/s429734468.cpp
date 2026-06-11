#include<stdio.h>

int kuadrat(int a,int b){
	int total = 1;
	for(int i=1;i<=b;i++){
		total = total * a;
	}
	return total;
}
	
	int main(){
	
	int n;
	scanf("%d",&n);
	
	printf("%d",kuadrat(n,1) + kuadrat(n,2) + kuadrat(n,3));



		return 0;
	}