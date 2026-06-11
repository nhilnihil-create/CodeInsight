#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

bool same(vector<int> &a, vector<int> &b) {
    rep(i, a.size()) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> r(n);
    rep(i, n) {
        r[i] = i + 1;
    }
    vector<int> p(n);
    rep(i, n) {
        scanf("%d", &p[i]);
    }
    vector<int> q(n);
    rep(i, n) {
        scanf("%d", &q[i]);
    }
    int k = 0;
    int a, b;
    do {
        k++;
        if (same(p, r)) a = k;
        if (same(q, r)) b = k;
    } while (next_permutation(r.begin(), r.end()));
    printf("%d\n", abs(a - b));
}