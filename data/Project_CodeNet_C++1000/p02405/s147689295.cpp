//
//  main.cpp
//  ITP1_5-C
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
        
        if (H == 0 && W == 0){
            break;
        }
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                
                if (i == 0 || i % 2 == 0) {
                    // ??¶??°???
                    if ((i + j) == 0 || (i+j)%2 == 0) {
                        printf("#");
                    }else{
                        printf(".");
                    }
                }else if(i % 2 != 0){
                    //?\???°???
                    if ((i + j) == 0 || (i+j)%2 == 0) {
                        printf("#");
                    }else{
                        printf(".");
                    }

                }
            }
            
            printf("\n");
        }

                    printf("\n");
        
    }
    
    return 0;
}