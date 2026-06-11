#include <iostream> 
                    
int main() {        
    int h, w = 0;   
                    
    while(std::cin >> h >> w, h || w) {
        for(int i = h ; i; i--) {
            for(int j = w; j; j--) {
                if(i == h || i == 1 || j == w || j == 1) {
                    std::cout << "#";
                }else {
                    std::cout << ".";
                }   
            }       
            std::cout << std::endl;
        }           
        std::cout << std::endl;
    }               
                    
    return 0;       
}