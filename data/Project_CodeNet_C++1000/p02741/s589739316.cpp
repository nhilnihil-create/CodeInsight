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
    
    int a[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    
    int k;
    
    cin >> k;
    
    cout << a[k-1] << endl;
    
    
    
    return 0;
}
