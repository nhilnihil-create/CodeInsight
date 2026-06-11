#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

const int INF = 1000000000;

int main() {
    int N, K, S;
    cin >> N >> K >> S;

    int A[N];
    if (S == INF) {
        for (int i=0; i<K; i++) A[i] = S;
        for (int i=K; i<N; i++) A[i] = INF -1;
    } else {
        for (int i=0; i<K; i++) A[i] = S;
        for (int i=K; i<N; i++) A[i] = INF;
    }

    rep(i, N) cout << A[i] << " ";
    cout << endl;

    return 0;
}