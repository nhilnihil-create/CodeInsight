#include<iostream>

int main(void){
    long long a, b, k;
    std::cin >> a >> b >> k;
    if(a >= k){
	a -= k;
	std::cout << a << " " << b << std::endl;
	return 0;
    }else{
	k = k - a;
	a = 0;
	if(b >= k){
	    b -= k;
	    std::cout << a << " " << b << std::endl;
	}else{
	    std::cout << a << " " << 0 << std::endl;
	}
    }
}
