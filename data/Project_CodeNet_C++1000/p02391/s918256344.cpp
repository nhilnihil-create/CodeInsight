#include<iostream>
int a,b;
int main(){
	std::cin>>a>>b;
	std::cout<<"a";
	(a<b)?std::cout<<" < ":(a>b)?std::cout<<" > ":std::cout<<" == ";
	std::cout<<"b"<<std::endl;
	return 0;
}