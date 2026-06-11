#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    long long k;
    cin >> n >> k >> q;

    vector<long long> p(n, k - q);

    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        p.at(--a)++;
    }

    for (int i = 0; i < n; i++)
        cout << (p.at(i) > 0 ? "Yes" : "No") << endl;
}