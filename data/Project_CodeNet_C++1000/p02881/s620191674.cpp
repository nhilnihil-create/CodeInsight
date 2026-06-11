#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    long long n;
    cin >> n;

    long long ans = 1e17;
    for (long long i = 1; i * i <= n; i++) {
        if (n%i == 0) {
            long long d = i+n/i-2;
            ans = min(ans, d);
        }
    }

    cout << ans << endl;
    return 0;
}
