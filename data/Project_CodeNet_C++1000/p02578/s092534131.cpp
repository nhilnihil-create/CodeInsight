//
//  main.cpp
//  AtCoderABC176
//
//  Created by Glen Cahilly on 9/2/20.
//  Copyright © 2020 Glen Cahilly. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

/*

Problem A

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
*/

//Problem B

/*
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    long count=0;
    for (int k=0; k<s.size(); k++) {
        count+=s[k]-48;
    }
    if (count%9==0) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}
*/

//Problem C

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    long long prev; cin >> prev;
    long long count=0;
    for (int k=0; k<n-1; k++) {
        long long in; cin >> in;
        if (in-prev<0) {
            count+=prev-in;
        } else {
            prev=in;
        }
        
    }
    cout << count << "\n";
}