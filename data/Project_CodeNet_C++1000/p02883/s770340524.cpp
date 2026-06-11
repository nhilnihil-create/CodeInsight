
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
int n;
ll k;
ll A[N], F[N];

bool check(ll s) {
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] * F[i] > s) {
            ll nc = s / F[i]; // new coefficient
            cnt += A[i] - nc;
        }
    }
    return cnt <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> F[i];
    }
    sort(A, A + n); // non-decreasing order
    sort(F, F + n, greater<int>());

    ll l = 0, r = 1e12;
    while (l < r) {
        ll m = (r - l) / 2 + l;
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << endl;

    return 0;
}

