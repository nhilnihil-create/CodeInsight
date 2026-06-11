/**
 *    author:  Taichicchi
 *    created: 12.09.2020 22:37:28
 **/

#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int gcd(int p, int q) {
    while (q != 0) {
        int r = p % q;
        p = q;
        q = r;
    }
    return p;
}

int main() {
    int K;
    cin >> K;

    int ans = 0;

    for (int a = 1; a <= K; ++a) {
        for (int b = 1; b <= K; ++b) {
            for (int c = 1; c <= K; ++c) {
                ans += gcd(a, gcd(b, c));
            }
        }
    }
    cout << ans << endl;

    return 0;
}