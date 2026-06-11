#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    ll cnt = 0;
    for (int i = 1; i < N; i++) cnt += (N-1) / i;
    cout << cnt << endl;
}
