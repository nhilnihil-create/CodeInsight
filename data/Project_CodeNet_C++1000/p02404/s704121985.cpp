//
//  main.cpp
//  ITP1_5-B
//
//  Created by Saicj on 2015/07/14.
//  Copyright (c) 2015??´ saicj. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, const char * argv[])
{

    int H,W;
    
    while (true) {
        cin >> H >> W;
        
        if ( H == 0 && W == 0) {
            break;
        }
        
        int i, j;
        for ( i = 0; i < H; i++ ){
            for ( j = 0; j < W; j++ ){
                if( j > 0 && j < W-1 && i > 0 && i < H-1){
                    printf(".");
                } else {
                    printf("#");
                }
            }
            printf("\n");
        }
        
        printf("\n");
    }
    
    return 0;
}