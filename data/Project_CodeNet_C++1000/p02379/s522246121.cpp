//
//  main.cpp
//  ITP1_10-A
//
//  Created by Saicj on 2015/08/05.
//  Copyright (c) 2015??´ saicj. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cstdio>
#include <iomanip>

/**
 ?¨??????????
 ?????¢= sqrt( (x1-x2)^2 + (y1-y2)^2 )
 */

int main(int argc, const char * argv[]) {

    double p1X;
    double p1Y;
    
    double p2X;
    double p2Y;
    
    std::cin >> p1X >> p1Y >> p2X >> p2Y;
    
    double result = sqrt(pow(p1X - p2X, 2) + pow(p1Y - p2Y, 2));

    
    printf("%.10lf\n", result);
    
    return 0;
}