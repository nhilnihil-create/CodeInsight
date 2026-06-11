#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    
    return a;
}

int solve(int K) {
    int res = 0;
    for (int i = 1; i <= K; ++i) {
        for (int j = 1; j <= K; ++j) {
            int a = gcd(i, j);
            for (int k = 1; k <= K; ++k) {
                res += gcd(a, k);
            }
        }
    }

    return res;
}

int main() {
    int K; cin >> K;
    cout << solve(K) << endl;
}