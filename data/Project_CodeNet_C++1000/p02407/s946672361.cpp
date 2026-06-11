#include <iostream>
#include <cstdio>
int main(){
	int n,i;
	std::cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		std::cin>>a[i];
	}
	for(i=n-1;0<=i;i--){
		std::cout<<a[i];
		if(i!=0)
			std::cout<< " ";
	}
	std::cout<<std::endl;
	return 0;
}