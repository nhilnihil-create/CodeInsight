#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    vector<int> L(N);
    rep(i,N) cin >> L.at(i);
    sort(L.begin(), L.end());
    ll res = 0;
    rep(i,N) {
        for (int j = i + 1; j < N; j++) {
            auto x = lower_bound(begin(L), end(L), L[i] + L[j]);
            size_t k = distance(begin(L), x);
            res += k - 1 - j;
        }
    }

    cout << res << endl;
}
