//
//  main.cpp
//  ITP1_10-B
//
//  Created by Saicj on 2015/08/05.
//  Copyright (c) 2015??´ saicj. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

#define PI 3.1415926

int main(int argc, const char * argv[]) {

    
    double a,b,C;
    
    cin >> a >> b >> C;
    
    /**
     *  ??¢?§????(???/???)?????????sin??
     ??¨??? a^2 + b^2 -2ab*cosC = c^2
     a + b + c
     
     
     */

    double rad = C * PI / 180.0;
    
    double area = (a * b)/2 * sin(rad);
    
    double c = sqrt(pow(a, 2) + pow(b, 2) - (2 * a * b * cos(rad)));
    
    double perimeter = a + b + c;
    
    double h = (area * 2) / a;
    
    printf("%.4lf %.4lf %.4lf \n", area, perimeter, h);
    
    
    return 0;
}