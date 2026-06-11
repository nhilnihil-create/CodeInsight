//
//  main.cpp
//  AOJ1129
//
//  Created by aki33524 on 2014/07/15.
//  Copyright (c) 2014年 aki33524. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[])
{
    int n, r;
    while(cin>>n>>r, n|r){
        vector<int> deck(n);
        for(int i=0; i<n; i++)
            deck[n-i-1] = i+1;
        
        int p, c;
        for(int i=0; i<r; i++){
            cin >> p >> c;
            vector<int> tmp = deck;
            for(int j=0; j<c; j++){
                deck[j] = tmp[j+p-1];
            }
            for(int j=0; j<p-1; j++){
                deck[j+c] = tmp[j];
            }
        }
        cout << deck[0] << endl;
    }
    
    return 0;
}