#include <iostream>
int main(){
    int H,W,i,j;
    while(true){
        std::cin >> H >> W;
        if(H==0 && W==0) break;
        for(i = 0; i< H ; i++){
            for(j=0;j<W;j++){
                std::cout << "#";
            }
            std::cout << std::endl;
        }
        std::cout  << std::endl;
    }
    return 0;
}
