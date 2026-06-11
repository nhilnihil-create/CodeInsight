#include <bits/stdc++.h>
using namespace std;




























int main () {
    long long N;
    cin >> N;
    long long sum = 0;
    for (long long i = 1; i <= N; i++) {
        sum += i * (N / i) * (N / i + 1) / 2;
    }

    cout << sum << endl;
}