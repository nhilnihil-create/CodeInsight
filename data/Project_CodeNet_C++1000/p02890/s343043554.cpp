#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> C(n + 1, 0), D(n + 1, 0), skD(n + 1), sD(n + 1), f(n + 1);
    for (int i = 0; i < n; i++) {
        int A;
        cin >> A;
        C[A]++;
    }
    for (int i = 0; i <= n; i++) {
        D[C[i]]++;
    }
    skD[0] = 0;
    sD[0] = D[0];
    for (int i = 1; i <= n; i++) {
        skD[i] = skD[i - 1] + i * D[i];
        sD[i] = sD[i - 1] + D[i];
    }
    f[0] = n;
    for (int i = 1; i <= n; i++) {
        f[i] = (skD[i] + i * (sD[n] - sD[i])) / i;
    }
    reverse(f.begin(), f.end());
    for (int i = 1; i <= n; i++) {
        int j = lower_bound(f.begin(), f.end(), i) - f.begin();
        cout << n - j << endl;
    }
    return 0;
}