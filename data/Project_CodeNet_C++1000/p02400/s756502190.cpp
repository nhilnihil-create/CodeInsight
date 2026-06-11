#include<iostream>
#include<cstdio>

int main(){
	
	double r,S,L;
	double pi = 3.14159265358979323846  ;
	
	std::cin >>r;
	S=pi*r*r, L=2*pi*r;	
	printf("%.8f %.8f",S,L);
	
	return 0;
	
}