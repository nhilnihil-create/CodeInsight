//
//  ROIGold.cpp
//  Main calisma
//
//  Created by Rakhman on 05/02/2019.
//  Copyright © 2019 Rakhman. All rights reserved.
//

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iterator>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define FOR(i, start, finish, k) for(int i = start; i <= finish; i += k)

const int MXN = 1e5 + 5;
const long long MNN = 2e3 + 200;
const long long MOD = 10;
const long long INF = 1e18;
const int OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

llong n;
llong b[MXN], mx, cnt[65], ans;
llong sum;

llong maxXor(llong n){
    for (long long q = 60; q >= 0; --q) {
        for(llong j = 1; j <= n; j++) {
            if(((1LL << q) & b[j])) {
                int ok = 1;
                for (long long t = q + 1; t <= 60; ++t) {
                    if (((1LL << t) & b[j]) != 0) {
                        ok = 0;
                        break;
                    }
                }
                if (ok == 0) continue;
                for (int t = 1; t <= n; ++t) {
                    if (t == j) continue;
                    if ((1LL << q) & b[t]) {
                        b[t] ^= b[j];
                    }
                }
                break;
            }
        }
    }
    llong res = 0;
    for (llong i = 1; i <= n; i++) {
        //cout << b[i] << ' ';
        res ^= b[i];
    }
    //cout << nl;
    return res;
}

int main(){
    ios;
    cin >> n;
    for(llong i = 1; i <= n; i++){
        cin >> b[i];
        for(llong j = 61; j >= 0; j--){
            if((b[i] >> j) & 1){
                cnt[j]++;
            }
        }
    }
    for(llong i = 0; i <= 61; i++){
        if(cnt[i] % 2 == 1){
            ans += (1LL << i);
            for(llong j = 1; j <= n; j++) {
                if((b[j] >> i) & 1){
                    b[j] ^= (1LL << i);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        //cout << b[i] << ' ';
        sum ^= b[i];
    }
    //cout << nl;
    llong mx = maxXor(n);
    cout << (sum ^ mx) + mx + ans;
    return 0;
}
