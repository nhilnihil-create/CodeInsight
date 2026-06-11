//
//  main.cpp
//  AtCoderABC176
//
//  Created by Glen Cahilly on 9/2/20.
//  Copyright © 2020 Glen Cahilly. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double n, x, t;
    cin >> n >> x >> t;
    if (x==0) {
        cout << 0 << "\n";
    } else {
        long k = ceil(n/x)*t;
        cout << k << "\n";
        
    }
}
