#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int64_t N, K;
    cin >> N >> K;
    int64_t n = K;
    int64_t count = 1;
    while (n - 1 < N) {
        n = n * K;
        count += 1;
    }

    cout << count << endl;
    return 0;
}