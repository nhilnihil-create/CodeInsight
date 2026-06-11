#include <bits/stdc++.h>

using namespace std;

vector<int> next_int_vector(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v.at(i);
    }
    return v;
}

int main() {
    // https://img.atcoder.jp/abc172/editorial.pdf
    int n;
    cin >> n;

    long ans = 0;
    for (int i = 1; i <= n; ++i) {
        long y = n / i;
        ans += y * (y + 1) * (long) i / 2;
    }
    cout << ans << endl;
}
