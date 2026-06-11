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
    double a, b, c, x;
    double S, L, h;
    
    cin >> a >> b >> x;
    
    x = x/360 * 2 * M_PI; // ??????rad?????????
    h = b * sin(x);
    c = sqrt( a*a + b*b - 2*a*b*cos(x) );
    L = a + b + c;
    S = a*h/2;
    
    cout << setprecision(5) << fixed << S << endl;
    cout << fixed << setprecision(5) << L << endl;
    cout << fixed << setprecision(5) << h << endl;
    
    return 0;
    
}