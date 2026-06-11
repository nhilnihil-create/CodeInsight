#include <bits/stdc++.h>
using namespace std;

long long nCr(const long long n, long long r) {
    if (n == 0) { return 0; }
    if (r == 0) { return 1; }
    if (r == 1) { return n; }
    if (n == r) { return 1; }

    if (r > n / 2) { r = n / 2; }

    long long result = 1;
    for (long long i = 1; i <= r; i++) { result *= (n - i + 1) / i; }

    return (result);
}

int main() {
    //
    long long num;
    string str;
    long long kekka = 0;

    map<string, long long> m;

    cin >> num;

    for (long long i = 0; i < num; i++) {
        cin >> str;
        sort(str.begin(), str.end());
        m[str]++;
    }

    for (auto itr : m) {
        if (itr.second < 2) continue;
        long long tmp = itr.second-1;
        kekka += tmp * (tmp + 1) / 2;
    }

    cout << kekka;
}