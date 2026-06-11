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
    string ring, problem;
    string partofring;
    
    cin >> ring >> problem;
    
    int size = problem.size();
    int maxsize = ring.size();
    bool ans = false;
    
//    cout << size << " " << maxsize << endl;
    
    for(int i=0; i<maxsize; i++) {
        if( i+size < maxsize) {
            partofring = ring.substr(i, size);
        } else {
            partofring = ring.substr(i, maxsize-i) + ring.substr(0, size-(maxsize-i) );
        }
        
        if( partofring == problem ) {
            ans = true;
            break;
        }
//        cout << partofring << " " << ans << endl;
        
    }

    //output
    if(ans) cout << "Yes";
    else cout << "No";
    cout << endl;
    
    return 0;
    
}