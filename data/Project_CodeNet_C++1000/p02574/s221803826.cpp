#include <bits/stdc++.h>
using namespace std;

int main() {
    const int limit = 1e6 + 5;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v(limit), primes;
    fill(v.begin(), v.end(), 1);
    // v[1] = 0;
    for (int i = 2; i <= limit; i++) {
        if (!v[i]) continue;
        primes.push_back(i);
        for (int j = 2 * i; j < n; j += i) {
            v[j] = 0;
        }
    }
    vector<int> mark(limit);
    bool pairwise = true;
    for (int x : a) {
        int t = x;
        for (int p : primes) {
            if (p * p > t) break;
            if (t % p == 0) {
                if (mark[p]) {
                    pairwise = false;
                    break;
                }
                mark[p] = 1;
                while (t % p == 0)
                    t /= p;
            }
        }
        if (v[t] && t != 1) {
            if (mark[t])
                pairwise = false;
            mark[t] = 1;
        }
        if (!pairwise)
            break;
    }
    if (pairwise) {
        cout << "pairwise coprime\n";
        return 0;
    }
    int g = a[0];
    for (int x : a) {
        g = __gcd(g, x);
    }
    if (g == 1)
        cout << "setwise coprime\n";
    else
        cout << "not coprime\n";
}
