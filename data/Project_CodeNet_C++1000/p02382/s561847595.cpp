//
//  main.cpp
//  ITP1_10-D
//
//  Created by ?????¶??? on 15/8/15.
//  Copyright (c) 2015??´ ?????¶???. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;
    
    double x[n],y[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> y[i];
    }
    
    // p = 1 ???????????????????????¢
    
    double result_1 = 0;
    for (int i = 0; i < n; i++) {
        
        result_1 += abs(x[i] - y[i]);
    }
    
    
    // p = 2 ???????????????????????¢
    
    double result_2 = 0;
    for (int i = 0; i < n; i++) {
        result_2 +=  pow(abs(x[i] - y[i]), 2.0);
    }
    
    result_2 = sqrt(result_2);
    
    // p = 3
    
    double result_3 = 0;
    for (int i = 0; i < n; i++) {
        result_3 += pow(abs((x[i] - y[i])), 3.0);
    }
    result_3 = cbrt(result_3);
    
    // max ?????§????????§????????¢
    vector<double> tempList;
    
    for (int i = 0; i < n; i++) {
        
        double temp = abs(x[i] - y[i]);
        tempList.push_back(temp);
    }
    
 
    auto it = max_element(tempList.begin(), tempList.end());
    double result_4 = *it;
    
    printf("%.6f\n", result_1);
    printf("%.6f\n", result_2);
    printf("%.6f\n", result_3);
    printf("%.6f\n", result_4);
    
    return 0;
}