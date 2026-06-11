//
//  volume0-0.cpp
//  
//
//  Created by anthony on 2014/11/19.
//
//

#include <iostream>


using namespace std;

int main(){
    
    for (int m = 1; m <= 9; m++) {
        for (int n = 1; n <= 9; n++) {
            int result;
            
            result = n * m;
            cout << m << "x" << n << "=" << result << endl;
        }
    }
    
    return 0;
}