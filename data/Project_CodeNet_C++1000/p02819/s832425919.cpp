#include<iostream>

int main(void){
    int x;
    std::cin >> x;

    bool flag;
    while(true){
	flag = true;
	for(int i = 2; i < x; i++){
	    if(x % i == 0){
		flag = false;
		break;	
	    }
	}
	if(flag) break;
	x++;
    }
    std::cout << x << std::endl;
    return 0;
}

