#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int p[10], q[10], a[10], b[10];

bool check(int *x, int *y, int n) {
    for (int i=0;i<n;i++) {
        if (x[i]!=y[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;i++) cin >> p[i];
    for (int i=0;i<n;i++) cin >> q[i];
    for (int i=0;i<n;i++) {
        a[i] = i+1;
        b[i] = i+1;
    }

    int cntA = 0, cntB = 0;
    while (!check(a, p, n)) next_permutation(a, a+n), cntA++;
    while (!check(b, q, n)) next_permutation(b, b+n), cntB++;
    cout << abs(cntA-cntB) << endl;
}
