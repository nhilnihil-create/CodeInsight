#include<stdio.h>
int main(){
	int a, flag;
	scanf("%d", &a);
	char b[a+1];
	scanf("%s", b);
	if(a%2==1){
		printf("No");
	}
	else{
		int flag=1;
	for(int i=0; i<a/2; i++){
		if((b[i]!= b[i+a/2])){
			flag=0;
		}
	}
	if(flag){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
}
	
	return 0;
}