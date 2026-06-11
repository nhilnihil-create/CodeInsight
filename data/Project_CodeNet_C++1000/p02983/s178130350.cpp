#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
using namespace std;

int main() {
    //input
    long l,r; cin >> l >> r;
    int M = 2019;

    //compute
    if(r - l >= 2018){
        cout << 0 << endl;
        return 0;             
    }
  
    long long rmin;
    rmin = ((l % M) * (r % M)) % M;
  
    l = l % M;
    r = r % M;

    for(int i = 0;i < r - l + 1; i++) {
        for(int j = i + 1; j < r - l + 1 ; j++){
            long long tmp;
            tmp = ((l + i) % M) * ((l + j) % M) % M;
            if(tmp < rmin){
                rmin = tmp;         
            }
        } 
    }

    //output
    cout << rmin << endl;
}
