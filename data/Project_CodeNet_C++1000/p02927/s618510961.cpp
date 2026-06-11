//
//  main.cpp
//  Study
//
//  Created by 佐々木勇星 on 2020/03/12.
//  Copyright © 2020 佐々木勇星. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;


int main(int argc, const char * argv[]) {

    int m, d, ans = 0;
    
    cin >> m >> d;
    
    for(int i=11; i<=d; i++)
    {
        int d10 = i / 10;
        int d1 = i - d10 * 10;
        
        if(d1 <= 1 || d10 <= 1) continue;
        
        for(int j=1; j<=m; j++)
        {
            if( d10 * d1 == j) {
                ans++;
                //cout << "d10 = " << d10 << ", d1 = " << d1 << endl;

                //cout << "m = " << j << endl;
            }
        }
        
    }
    
    cout << ans << endl;
    
    return 0;
    
}
