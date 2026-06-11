#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int r = round(sqrt(n));
    long long ans = LLONG_MAX;
    for (int i = 1; i <= r; i++) {
        if (n%i == 0) {
            long long tmp = i-1 + n/i-1;
            ans = min (ans, tmp);
        }
    }
    cout << ans << endl;
}