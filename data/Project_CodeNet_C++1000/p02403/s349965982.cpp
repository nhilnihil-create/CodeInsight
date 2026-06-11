//
//  main.cpp
//  ???tp?????????a
//
//  Created by ???????????¬ on 2015/08/02.
//  Copyright (c) 2015??´ Home. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    long long h,w;
    
    while (1){
        cin >>h >>w;
        if (h==0&& w==0)break;
        
        for ( long long i = 0; i < h; i++ ){
            for ( long long j = 0; j < w; j++ ){
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;

    }

    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}