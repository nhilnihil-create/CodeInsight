#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N; cin >> N;
    if (N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll M = 10;
    ll res = 0;
    while (N / M > 0) {
        res += N / M;  
        M *= 5;
    }
    cout << res << endl;
}
