//
//  main.c
//  ITP1_5_A
//
//  Created by ??±??°?????? on 2015/10/10.
//  Copyright ?? 2015??´ HamadaShogo. All rights reserved.
//

#include <stdio.h>

void printSquare(unsigned int High, unsigned int Wide);

int main(int argc, const char * argv[]) {
    unsigned int h = 1, w = 1;
    
    while (!(h == 0 && w == 0)) {
        scanf("%d %d", &h, &w);
        if(!(h == 0 && w == 0)){
            printSquare(h, w);
        }
    }

    return 0;
}

void printSquare(unsigned int High, unsigned int Wide){
    int i, j;
    
    for (i=0; i<High; i++) {
        for (j=0; j<Wide; j++) {
            printf("#");
        }
        puts("");
    }
    puts("");
}