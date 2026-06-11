#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    cin >> N >> K;
    N %= K;
    if (N > abs(N - K))
        N = abs(N - K);
    cout << N << endl;
}