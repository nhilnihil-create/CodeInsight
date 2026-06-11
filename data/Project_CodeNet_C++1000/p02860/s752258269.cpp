#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	char str[n+1];
	scanf("%s", str);
	int sum1=0, sum2=0;
	for(int i=0; i<n/2; i++){
		sum1+=str[i];
	}
	for(int i=n/2; i<n; i++){
		sum2+=str[i];
	}
	if(sum1==sum2){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	
	return 0;
}