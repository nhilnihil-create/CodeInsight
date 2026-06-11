#include <stdio.h>
int main(){
	int n, n1, n2, n3;
	scanf("%d", &n);
	n1=n%10;
	n2=(n/10)%10;
	n3=n/100;
		if(n1==7){
		puts("Yes");
}
		else if(n2==7){
		puts("Yes");			
}
		else if(n3==7){
		puts("Yes");
}
		else{
		puts("No");
}
	return 0;
}