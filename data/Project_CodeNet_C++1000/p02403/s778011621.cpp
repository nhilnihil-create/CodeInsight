#include <iostream>
#include <cstdio>
         
int main() {
    int h, w = 0;
    while(true) {
        std::cin >> h >> w;
        if(!h && !w) break;
         
        for(int i = 0; i < h; i++) {        
            for(int j = 0; j < w; j++) {
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }    
    return 0;
}