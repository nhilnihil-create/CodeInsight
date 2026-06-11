#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N; cin >> N;
    vector<int> A(N), B(N);
    ll wa = 0;
    rep(i,N) {
        cin >> A.at(i);
        wa += A[i];
    }

    ll x1 = wa;
    for (int i = 1; i < N-1; i += 2) x1 -= 2 * A[i]; 
    cout << x1;
    rep(i, N-1) {
        cout << " ";
        int xn = 2 * A[i] - x1;
        cout << xn;
        x1 = xn;
    }
    cout << endl;
}
