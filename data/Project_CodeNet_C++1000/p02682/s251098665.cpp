/**
*    author:  Taichicchi
*    created: 07.09.2020 21:33:09
**/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll A, B, C, K;
    cin >> A >> B >> C >> K;

    ll ans = 0;

    if(A >= K) {
        ans = K;
    } else if(A + B >= K) {
        ans = A;
    } else if(A + B + C >= K){
        ans = A - (K - A - B);
    } else {
        ans = A - C;
    }

    cout << ans << endl;
    return 0;
}