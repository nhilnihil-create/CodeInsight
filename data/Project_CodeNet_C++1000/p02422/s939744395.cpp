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
    string str;
    int numOfCmd;
    string cmd;
    int from, to;
    string rep;
    
    cin >> str >> numOfCmd;
    
    for(int i=0; i<numOfCmd; i++) {
        cin >> cmd;
        
        if( cmd == "print" ) {
            cin >> from >> to;
            cout << str.substr(from, to-from+1) << endl;
        }
        
        else if( cmd == "reverse") {
            cin >> from >> to;
            reverse(str.begin()+from, str.begin()+to+1);
//            cout << str << endl;
        }
        
        else if( cmd == "replace") {
            cin >> from >> to >> rep;
            int j = 0;
            for(int i=from; i<=to; i++) {
                str[i] = rep[j++];
            }
//            cout << str << endl;
        }
        
    }
    
    return 0;
    
}


//abcde
//3
//replace 1 3 xyz
//reverse 0 2
//print 1 4