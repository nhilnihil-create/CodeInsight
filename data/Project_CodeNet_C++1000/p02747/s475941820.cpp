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

using namespace std;


int main(int argc, const char * argv[]) {
    
    string s, ans = "No";
    cin >> s;
    
    for(int i=0; i<s.length(); i=i+2)
    {
        
        if(s[i] == 'h' && s[i+1] == 'i')
        {
            ans = "Yes";
        } else {
            ans = "No";
            break;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
