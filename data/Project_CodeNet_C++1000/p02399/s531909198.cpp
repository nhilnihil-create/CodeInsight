//
//  main.cpp
//  ITP1_4-A
//
//  Created by Saicj on 2015/07/14.
//  Copyright (c) 2015??´ saicj. All rights reserved.
//

#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{

    int a,b;
    
    cin >> a >> b;
    
//    if (b == 0){
//        b = 1;
//    }
    
    double f1 = a / b;
    double f2 = a % b;
    double f3 = 1.0 * a/b;
    
    printf("%.0lf ", f1);
    printf("%.0lf ", f2);
    printf("%.5lf\n",f3);
    
    
    return 0;
}

//int main() {
//    int a,b;
//    scanf("%d %d",&a, &b);
//    int d = a/b;
//    int r = a%b;
//    double f = double(a)/double(b);
//    
//    printf("%d %d %lf\n", d, r, f);
//    
//    return 0;
//}