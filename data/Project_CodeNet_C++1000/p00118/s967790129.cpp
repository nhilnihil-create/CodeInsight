//
//  main.cpp
//  Cwork
//
//  Created by admin on 2015/05/22.
//  Copyright (c) 2015??´ admin. All rights reserved.
//

#include <iostream>
using namespace std;

void append(char fruit[100][100], int (&map)[100][100], int count, int i, int j, int h, int w){
    if(j != w -1){
        if(map[i][j+1] == 0 && fruit[i][j+1] == fruit[i][j]){
            map[i][j+1] = count;
            append(fruit, map, count, i, j+1, h, w);
        }
    }
    
    if(i != h - 1){
        if(map[i+1][j] == 0 && fruit[i+1][j] == fruit[i][j]){
            map[i+1][j] = count;
            append(fruit, map, count, i+1, j, h, w);
        }
    }
    
    if(j != 0){
        if(map[i][j-1] == 0 && fruit[i][j-1] == fruit[i][j]){
            map[i][j-1] = count;
            append(fruit, map, count, i, j-1, h, w);
        }
    }
    
    if(i != 0){
        if(map[i-1][j] == 0 && fruit[i-1][j] == fruit[i][j]){
            map[i-1][j] = count;
            append(fruit, map, count, i-1, j, h, w);
        }
    }

}


int main(int argc, const char * argv[]) {
    
    while(true){
        int H,W;
        cin >> H >> W;
        if(H == 0 && W == 0){
            break;
        }
        
        
        int count = 0;
        int map[100][100] = {};
        char fruits[100][100] = {};
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cin >> fruits[i][j];
            }
        }
        
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(map[i][j] != 0){
                    continue;
                }else{
                    count++;
                    map[i][j] = count;
                    append(fruits, map, count, i, j, H, W);
                }
                
            }
        }
        
        cout << count << endl;
    }
        return 0;
}