#include <bits/stdc++.h>
using namespace std;

int main(void) {
    long long n, a, b;
    cin >> n >> a >> b;
    long long k = a + b;
    long long rest = n % k;
    long long l = n / k;
    cout << a * l + min(a, rest) << endl;
    return 0;
}