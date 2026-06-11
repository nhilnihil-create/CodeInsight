#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    vector<bool> A(N+1), B(N+1);
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        A.at(i) = a;
    }

    int M = 0;
    int cnt = 0;
    for (int i = N; i > 0; i--) {
        int p = 0;
        for (int j = i + i; j <= N; j += i) {
            p += B[j];
        }
        if (A[i] == p % 2) continue;
        B[i] = 1;
        cnt++;
        if (M < i) M = i;
    }
    cout << cnt << endl;
    if (M == 0) return 0;
    for (int i = 1; i <= M; i++) {
        if (B[i] == 1) {
            cout << i;
            if (i != M) cout << " ";
        }
    }
    cout << endl;
}
