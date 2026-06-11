//
//  main.c
//  ITP1_5_B
//
//  Created by ??±??°?????? on 2015/10/10.
//  Copyright ?? 2015??´ HamadaShogo. All rights reserved.
//

#include <stdio.h>

void printSquareF(unsigned int High, unsigned int Wide);

int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned int w = 1, h = 1;
    
    while (!(h == 0 && w == 0)) {
        scanf("%d %d", &h, &w);
        if(!(h == 0 && w == 0)){
            printSquareF(h, w);
        }
    }
    
    return 0;
}

void printSquareF(unsigned int High, unsigned int Wide){
    int i, j;
    
    for (i=0; i<High; i++) {
        for (j=0; j<Wide; j++) {
            if (i == 0 || i + 1 == High || j == 0 || j + 1 == Wide) {
                printf("#");
            }
            else{
                printf(".");
            }
        }
        puts("");
    }
    puts("");
}