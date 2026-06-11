#include<iostream>

int main(void){
    int n;
    std::cin >> n;
    int a;
    for(int i = 0; i < n; i++){
	std::cin >> a;
	if(a % 2 == 0){
	    if(a % 3 != 0 && a % 5 != 0){
		std::cout << "DENIED" << std::endl;
		return 0;
	    }
	}
    }
    std::cout << "APPROVED" << std::endl;
    return 0;
}

