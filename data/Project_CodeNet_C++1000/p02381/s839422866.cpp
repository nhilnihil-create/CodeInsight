//
//  main.cpp
//  ITP1_10-C
//
//  Created by Saicj on 2015/08/05.
//  Copyright (c) 2015??´ saicj. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;


int main(int argc, const char * argv[]) {
    
    double n;
    
    double num;
    
    
    while (true) {
        
        cin >> n;
        
        std::vector<double> nums(n);
        
        if (n == 0){
            break;
        }
        
        for (int i = 0; i < n; i++) {
            
            cin >> num;
            nums[i] = num;
        }
        
//        cout << "nums[0]" << nums[0] << endl;
        
        double sum = 0;
        
        for (int i = 0; i < n; i++){
            sum +=nums[i];
        }

//        cout << sum << endl;
        
        double m = sum/n;
        
//        cout << "m:" << m << endl;
        
        double mSum = 0;
        for (int i = 0; i < n; i++) {
            mSum += pow(nums[i]-m, 2);
            
//            cout << i << ":" << mSum << endl;
        }
        
//        cout << "mSum:" << mSum << endl;
        
        double result = sqrt(mSum/n);
        
        printf("%.8lf \n", result);
        
    }
    
    return 0;
}