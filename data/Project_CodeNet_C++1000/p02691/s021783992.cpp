#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N; cin >> N;
    vector<int> A(N);
    map<int,int> M;
    rep(i, N) {
        cin >> A[i];
        M[i-A[i]]++;
    }

    ll sum = 0;
    rep(i,N) {
        if (M.count(i+A[i]) > 0) sum += M[i+A[i]];
    }
    cout << sum << endl;
}
