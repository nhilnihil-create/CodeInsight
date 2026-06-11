#include<iostream>

int main(){
	
	int S , h , m , s;
	
	std::cin >> S;
	
	s = S % 60 , m =(S/60)%60 , h=S/3600 ;

    std::cout << h << ":"<<m<<":"<<s<<"\n";
	
	return 0;
	
}