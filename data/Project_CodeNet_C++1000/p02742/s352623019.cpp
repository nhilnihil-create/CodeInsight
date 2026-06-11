#include <iostream>
#include <vector>
#include <algorithm>

constexpr int INF = 1145141919;

int main(){
	std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    long long H, W;
    std::cin >> H >> W;

    if(H==1){
        std::cout << 1;
    }else if(W==1){
        std::cout << 1;
    }else if( H%2==0 || W%2==0 ){
        long long n = H*W/2;
        std::cout << n;
    }else{
        long long n = (H+1)*W/2 - (long long)W/2.0 + 1;
        std::cout << n;
    }

    return 0;
}
