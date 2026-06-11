#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b;
    cin >> n >> a >> b;

    long long rem = n % (a + b);
    long long sum = a * (n / (a + b));
    if (rem >= a) {
        sum += a;
    } else {
        sum += rem;
    }

    cout << sum << endl;

    return 0;
}
