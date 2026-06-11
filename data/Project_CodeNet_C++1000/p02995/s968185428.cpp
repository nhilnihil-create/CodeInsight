//
//  anti-division.cpp
//  my_programs
//
//  Created by Jiatuo Zou on 9/15/20.
//  Copyright © 2020 Jiatuo Zou. All rights reserved.
//

#include <iostream>

int main()
{
    using namespace std;
    
    long long a, b, lcm, c, d;
    cin >> a >> b >> c >> d;
    long long x = c, y = d;
    while(x != 0 && y != 0){
        x > y ? x %= y : y %= x;
        if(x == 0){
            lcm = c * d / y;
        } else if(y == 0){
            lcm = c * d / x;
        }
    }
    cout << b - a + 1 - b / c - b / d + b / lcm + (a - 1) / c + (a - 1) / d - (a - 1) / lcm << endl;
    return 0;
}
