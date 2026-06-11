#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long B = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        B ^= A[i];
    }
    for (int i = 0; i < N; ++i) cout << (B^A[i]) << endl;
}