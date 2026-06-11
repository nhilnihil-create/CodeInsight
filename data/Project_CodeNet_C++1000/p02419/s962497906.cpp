//
//  main.cpp
//  ITP1_9-A
//
//  Created by Saicj on 2015/08/03.
//  Copyright (c) 2015??´ saicj. All rights reserved.
//

#include <iostream>
#include <sstream> 
#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <cctype>
#include <cstdio>

using namespace std;

char ToUpper (char cX) { return toupper(cX); }

int main(int argc, const char * argv[]) {

    
    string W;
    cin >> W;
    
    transform(W.begin(), W.end(), W.begin(), ToUpper);
    
    
    string T;
    
    int index = 0;
    
    while (true) {
    
        cin >> T;
        
        if (T == "END_OF_TEXT") {
            break;
        }
        
         transform(T.begin(), T.end(), T.begin(), ToUpper);
        
        if (T == W){
            index++;
        }
    
        
    }
    
    cout << index << endl;

    
    return 0;
}