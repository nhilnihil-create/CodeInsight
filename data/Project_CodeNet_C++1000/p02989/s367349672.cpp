#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

constexpr int INFI = 1145141919;

int main(){
	std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<int> d;
    for(int i=0; i<N; i++){
        int buf;
        std::cin >> buf;
        d.push_back(buf);
    }

    std::sort(d.begin(), d.end());

    if(N%2!=0){
        std::cout << 0;
    }else{
        std::cout << d.at(N/2) - d.at(N/2-1);
    }

    return 0;
}
