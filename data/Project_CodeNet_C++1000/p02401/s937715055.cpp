#include <iostream>
#include <cstdio>
int main(){
	int a,b,ans,i;
	char op;
	while(1){
		std::cin >> a >> op >> b ;	
		if(op=='+') 
			ans = a + b;
		if(op=='-') 
			ans = a - b;
		if(op=='*') 
			ans = a * b;
		if(op=='/') 
			ans = a / b;
		if(op=='?') 
			break;
		std::cout << ans <<std::endl;
			}
	return 0;
}