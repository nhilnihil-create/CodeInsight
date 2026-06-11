//
//  main.cpp
//  ITP1_4-B
//
//  Created by Saicj on 2015/07/14.
//  Copyright (c) 2015??´ saicj. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, const char * argv[])
{

    double t = 3.141592653589;
    double r;
    cin >> r;
    
    double are = t * r * r;
    double cirle = 2 * t * r;
    
    printf("%.5f %.5f\n",are, cirle );
    
    

    
    return 0;
}