#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    int C[10][10] = {0};

    for (int i = 1; i <= N; i++) {
        int a = i % 10;
        int b = i / pow(10, (int)log10(i));
        C[b][a]++;
    }
    ll sum = 0;
    rep(i,10) rep(j,10) sum += C[i][j] * C[j][i];
    cout << sum << endl;
}
