//
//  main.cpp
//  AOJ_V0_0000
//
//  Created by anzai on 2015/08/06.
//  Copyright (c) 2015??´ anzai. All rights reserved.
//

#include<iostream>
using namespace std;

int main(){
    
    int i;
    int j;
    int k;
    
    for (i = 1; i < 10; i++ ){
        for (j = 1; j < 10; j++){
            k = i*j;
            cout << i << "x" << j << "=" << k << endl;
        }
    }
    
    
    
    
    return 0;
}