#include<iostream>

int main(void){
    int n, k;
    std::cin >> n >> k;
    int keta = 0;
    while(true){
	n /= k;
	keta++;
	if(n == 0){
	    break;
	}
    }
    std::cout << keta << std::endl;
    return 0;
}

