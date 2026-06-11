#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n, tmp;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = 0;
    }

    rep(i, n - 1) {
        cin >> tmp;
        a[tmp - 1]++;
    }

    rep(i, n) { cout << a[i] << endl; }

    return 0;
}