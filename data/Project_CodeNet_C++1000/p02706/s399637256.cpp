#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, A[10010];
    cin >> N >> M;
    for(int i = 0; i < M; i++) cin >> A[i];

    int total = 0;
    for(int i = 0; i < M; i++) {
        total += A[i];
    }

    if(total > N) {
        cout << -1 << endl;
    } else {
        cout << N - total << endl;
    }

    return 0;
}