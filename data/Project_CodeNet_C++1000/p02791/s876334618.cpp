#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;

const int MAX = 2e5;

int bit[MAX+1];

void add(int i, int x) {
    while (i <= MAX) {
        bit[i] += x;
        i += i & -i;
    }
}

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

int main() {
    // input
    int n;
    cin >> n;
    int p[n];
    rep(i, n) {
        cin >> p[i];
    }
    // solve
    int cnt = 0;
    rep(i, n) {
        if (sum(p[i]) == 0) cnt++;
        add(p[i], 1);
    }
    // output
    cout << cnt << endl;
}