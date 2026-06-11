//
//  main.c
//  ITP1_5_C
//
//  Created by ??±??°?????? on 2015/10/10.
//  Copyright ?? 2015??´ HamadaShogo. All rights reserved.
//

#include <stdio.h>

void printChessboard(unsigned int High, unsigned int Wide);

int main(int argc, const char * argv[]) {
    unsigned int w = 1, h = 1;
    
    while (!(h == 0 && w == 0)) {
        scanf("%d %d", &h, &w);
        if(!(h == 0 && w == 0)){
            printChessboard(h, w);
        }
    }
    
    return 0;
}

void printChessboard(unsigned int High, unsigned int Wide){
    int i, j;
    
    for (i=0; i<High; i++) {
        for (j=0; j<Wide; j++) {
            if ((i+j)%2 == 0) {
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