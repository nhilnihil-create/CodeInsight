#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N, K, S; cin >> N >> K >> S;
    vector<int> A;
    rep(i,K) A.push_back(S);
    int L = (S == 1000000000) ? 1 : S + 1;
    rep(i,N-K) A.push_back(L);
    rep(i,N) {
        cout << A[i];
        if (i != N-1) cout << " ";
    }
    cout << endl;
}
