#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    long long ans = 0, num = 10;
    while (num <= N) {
        ans += N / num;
        num *= 5;
    }

    cout << ans << endl;
    return 0;
}