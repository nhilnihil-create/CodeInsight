#include<iostream>
#include<cstdio>

int main(void){
	int a, b;
	
	std::cin >> a >> b;
	
	printf("%d %d %f\n",  a /b, a%b, (a*1.0)/b);
	
	return 0;
}