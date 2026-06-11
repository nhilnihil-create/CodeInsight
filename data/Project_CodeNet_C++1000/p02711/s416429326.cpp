#include<stdio.h>
int main(){
	int n,a1,a2,a3;
	scanf("%d", &n);
	
	a3=n % 10;
	a2=(n/10)%10;
	a1= n/100;
	
	if(a3==7){
	puts("Yes");
}
	else if(a2==7){
	puts("Yes");
}
	else if(a1==7){
	puts("Yes");
}
	else{
	puts("No");
}
	return 0;
}