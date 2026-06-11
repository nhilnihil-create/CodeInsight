#include<iostream>

int main(){

	int a=0,i,b;

	for(i=1;i<10;i++){
		a=a+1;
		for(b=1;b<10;b++){
			std::cout<<a<<"x"<<b<<"=";
			std::cout<<a*b<<std::endl;
		}
	}
	return 0;
}