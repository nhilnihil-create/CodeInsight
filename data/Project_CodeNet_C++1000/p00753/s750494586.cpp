//
//  main.cpp
//  AOJ1172
//
//  Created by aki33524 on 2014/07/06.
//  Copyright (c) 2014年 aki33524. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX_N = 250000;
bool is_prime[MAX_N];

void sieve(){
    for(int i=2; i<MAX_N; i++)
        is_prime[i] = true;
    for(int i=2; i<MAX_N; i++){
        if(is_prime[i]){
            for(int j=2*i; j<MAX_N; j+= i)
                is_prime[j] = false;
        }
    }
}

int main(int argc, const char * argv[])
{
    sieve();
    int n;
    while(cin>>n, n){
        int cnt = 0;
        for(int i=n+1; i<=2*n; i++)
            if(is_prime[i]) cnt++;
        cout << cnt << endl;
    }
    
    return 0;
}