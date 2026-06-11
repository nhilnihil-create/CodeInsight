#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long res = 0;
    for (long long A = 1; A * A < N; ++A) ++res;
    for (long long A = 1; A * A < N; ++A) {
        long long num = max((N - 1) / A - A, 0LL);
        res += num * 2;
    }
    cout << res << endl;
}