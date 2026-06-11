#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while(true){
        int h, w;
        std::cin >> h >> w;
        if(h==0 && w==0) break;
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                std::cout << "#";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    return 0;
}