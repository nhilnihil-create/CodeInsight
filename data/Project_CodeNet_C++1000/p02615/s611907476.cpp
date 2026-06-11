//
//  atcoder_abc173_d.cpp
//  CF-1
//
//  Created by Avaneendra Alugupalli on 8/4/20.
//  Copyright © 2020 Avaneendra Alugupalli. All rights reserved.
//

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    
    int i = 0;
    long long sum = 0;
    
    cin >> n;
    vector<int> frnd(n, 0);
    while (i < n) {
        cin >> frnd[i];
        i++;
    }
    
    sort(frnd.rbegin(), frnd.rend());
     
    sum = frnd[0]; //take the first element of increasing sorted array
    int reminder = n-2; // reminder of the elements
    i = 1;
    for(i = 1; reminder >= 0 && i < n; i++) {
        sum += (long) frnd[i] * min(2, reminder);
        reminder -= min(2, reminder);
    }
   
    
    cout << sum <<endl;
}
