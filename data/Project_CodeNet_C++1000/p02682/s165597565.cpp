#include<iostream>

int main(void){
    int a, b, c, k;
    std::cin >> a >> b >> c >> k;
    int ans;
    while(true){
	if(k <= a){
	    ans = k;
	    break;
	}else{
	    ans = a;
	    k -= a;
	}
	if(k <= b){
	    break;
	}else{
	    k -= b;
	}
	ans -= k;
	break;
    }

    std::cout << ans << std::endl;

    return 0;
}
