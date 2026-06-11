#include <iostream>    
                       
int main() {           
    int h, w = 0;      
    char point1[2] = {'#', '.'};
    char point2[2] = {'.', '#'};
                       
    while(std::cin >> h >> w, h || w) {
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(i % 2 == 0) {
                    std::cout << point1[j%2];
                }else {
                    std::cout << point2[j%2];
                }      
            }          
            std::cout << std::endl;
        }              
        std::cout << std::endl;
    }                  
                       
    return 0;          
}