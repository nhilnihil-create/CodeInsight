#include <bits/stdc++.h>

using namespace std;


long long f(int n) {
    if (n < 2) return 1;
    return n * f(n - 2);
}

long long d(long long n) {
    if (n % 10) {
        return 0;
    }
    return 1 + d(n / 10);
}

long long g(long long n) {
    if (n % 2 == 1) return 0;
    n /= 2;
    long long ans = 0;
    while (n > 0) {
        ans += n / 5;
        n /= 5;
    }
    return ans;
}

int main() {
    long long n;
    cin >> n;
    cout << g(n) << endl;
}
