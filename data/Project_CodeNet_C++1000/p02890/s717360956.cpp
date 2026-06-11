#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x]++;
    }
    vector<int> b(n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        b[a[i]]++;
    }
    int last = n;
    int s = n;
    for (int k = 1; k <= n; ++k) {
        while (last > s / k) {
            s -= b[last];
            b[last - 1] += b[last];
            last--;
        }
        cout << last << '\n';
    }
    return 0;
}
