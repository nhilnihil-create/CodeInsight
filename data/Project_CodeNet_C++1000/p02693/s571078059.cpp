#include<iostream>

int main(void){
    int k, a, b;
    std::cin >> k >> a >> b;
    for(int i = a; i <= b; i++){
	if(i % k == 0){
	    std::cout << "OK" << std::endl;
	    return 0;
	}
    }
    std::cout << "NG" << std::endl;
    return 0;
}

