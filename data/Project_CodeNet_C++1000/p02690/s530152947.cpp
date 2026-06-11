#include<iostream>
#include<vector>
#include<cmath>
int main(void){
    int x;
    std::cin >> x;
    bool flag = 0;
    for(int i = -1000; i < 1000; i++){
	for(int j = -1000; j < 1000; j++){
	    if(std::pow(i, 5) - std::pow(j, 5) == x){
		std::cout << i << " " << j << std::endl;
		flag = 1;
		return 0;
	    }
	}
    }
    return 0;
}
