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

//A-Z = 65 - 90
//a-z = 97 - 122

using namespace std;

int main(void) {
    string x;
    int sum;
    
    cin >> x;
    while( !(x=="0") ) {
        sum = 0;
        for( auto i:x ) {
            sum += i - '0';
        }
        cout << sum << endl;
        
        cin >> x;
    }
    
    return 0;
    
}