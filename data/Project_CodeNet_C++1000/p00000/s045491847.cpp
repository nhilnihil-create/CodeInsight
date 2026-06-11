#include<iostream>

int main(){
	int a=1,b=1,i,n;

	for(i=1;i<=9;i++){
		for(n=1;n<=9;n++){
		std::cout<<a<<"x"<<b<<"="<<a*b<<std::endl;
		b=n+1;
			}
		a=i+1;
		b=1;
		}
	
	return 0;
	}