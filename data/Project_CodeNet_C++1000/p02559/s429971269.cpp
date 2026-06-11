#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

long long tr[N], n, m;

int lowbit(int x) {
    return x & -x;
}

long long sum(int x) {
    long long sum = 0;
    for (int i = x; i; i -= lowbit(i)) sum += tr[i];
    return sum;
}

void modify(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += k;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        modify(i, x);
    }
    for (int i = 1; i <= m; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0) {
            modify(a + 1, b);
        } else {
            cout << sum(b) - sum(a) << '\n';
        }
    }
    return 0;
}