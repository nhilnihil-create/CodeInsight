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

    double x1, x2, y1, y2, dist;
    
    cin >> x1 >> y1 >> x2 >> y2;
    dist = sqrt( pow((x1-x2),2) + pow((y1-y2),2) );
    
    cout << fixed << setprecision(6) << dist << endl;
    
    return 0;
    
}