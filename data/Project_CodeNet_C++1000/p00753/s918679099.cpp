#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int MAX = 300000;
    bool isPrime[MAX];
    fill_n(isPrime, MAX, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 4; i < MAX; i += 2) {
        isPrime[i] = false;
    }
    for (int i = 3; i * i <= MAX; i += 2) {
        if (isPrime[i]) {
            for (int j = i * 2; j < MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        int res = 0;
        for (int i = n + 1; i <= n * 2; i++) {
            if (isPrime[i]) {
                res++;
            }
        }
        cout << res << endl;
    }
}