#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MAX = 123456 * 2 + 1;
    vector<bool> isPrime(MAX, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j < MAX; j += i)
                isPrime[j] = false;
        }
    }

    int n;
    for (;;) {
        cin >> n;
        if (n == 0) break;

        int ans = 0;
        for (int i = n + 1; i <= 2 * n; i++)
            if (isPrime[i]) ans++;

        cout << ans << endl;
    }
}