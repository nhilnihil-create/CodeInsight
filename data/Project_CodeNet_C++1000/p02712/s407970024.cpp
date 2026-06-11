#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<long long> fizzbuzz(n+1);

    for (size_t i = 1; i <= n; i++) fizzbuzz[i] = i;
    for (size_t i = 1; i <= 5; i++) {
        if (i != 3 && i != 5) continue;
        int m = i;
        while (m <= n) {
            fizzbuzz[m] = -1;
            m += i;
        }
    }

    long long ans = 0;
    for (size_t i = 1; i <= n; i++) {
        if (fizzbuzz[i] != -1) {
            ans += fizzbuzz[i];
        }
    }
    cout << ans << endl;
    return 0;
}
