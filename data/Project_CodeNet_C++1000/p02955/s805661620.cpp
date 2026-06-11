//
//  main.cpp
//  olymp
//
//  Created by Artur Sydoran on 26.09.2020.
//  Copyright © 2020 Artur Sydoran. All rights reserved.
//



#include "bits/stdc++.h"
#define fi first
#define se second

using namespace std;


#define int long long

int n, k;
int a[100005];

int check(int d){
    vector<int> r(n + 1);
    int sumR = 0;
    for (int i = 1; i <= n; i++){
        r[i] = a[i] % d;
        sumR += r[i];
    }
    if (sumR % d == 0){
        int k = n - sumR / d;
        sort(r.begin() + 1, r.begin() + n + 1);
        int ans = 0;
        for (int i = 1; i <= k; i++){
            ans += r[i];
        }
        if (ans <= ::k){
            return d;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

signed main() {
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    
    int ans = 0;
    for (int i = 1; i <= sqrt(sum); i++){
        if (sum % i == 0){
            ans = max(ans, check(i));
            ans = max(ans, check(sum / i));
        }
    }
    
    cout << ans << endl;
    
}

/*
1 1
 6 9 5
 0
 2 3
 4 5 4
 6 7 5
 0 1 2
 9
 1 60 100 60 100 60 100 60 1
 */
