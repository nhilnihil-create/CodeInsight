//
//  main.cpp
//  Test
//
//  Created by Nag on 2017/08/18.
//  Copyright ?? 2017??´ Nag. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

int main(void) {
    int n;
    int i;
    
    double mean, var, sigma;
    double tmp;
    
    cin >> n;
    
    while( n != 0 ) {
        double s[n];
        
        for(i=0; i<n; i++) {
            cin >> s[i];
        }
        
        //calc. mean
        tmp = 0;
        for(i=0; i<n; i++) {
            tmp += s[i];
        }
        mean = tmp / n;
        
        //calc. var.
        tmp = 0;
        for(i=0; i<n; i++) {
            tmp += pow( (s[i] - mean), 2 );
        }
        var = tmp / n;
        
        //calc. sigma
        sigma = sqrt(var);
        
        cout << fixed << setprecision(10) << sigma << endl;
        
        cin >> n;
    }
    
    return 0;
    
}