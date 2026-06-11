//  main.cpp
//  Sunkvežimiai (LMIO 2017)
//
//  Created by Augustinas Jucas on 05/10/2019.
//  Copyright © 2019 Augustinas Jucas. All rights reserved.
//
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//const int size = 200010;

int random(int a, int b){
    return a + rand() % (b-a+1);
}
double reiksme(double N, double K){
    for(int k = 1; k <= K; k++){
        if(N != 0) N = random(0, N-1);
        else N = 0;
    }
    return N;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    srand(time(0));
    int n;
    cin >> n;
    cout << (n-1)/2;
    return 0;
}
/*
 
 1 2 3 4 5 6 7 8 9
 1.5
 2
 
 s = (s * kek + sk)/(kek+1)
 = s/(kek+1) * kek + sk/(kek+1)
 
 */
