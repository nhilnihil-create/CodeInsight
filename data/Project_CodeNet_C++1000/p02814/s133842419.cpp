
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int n, m, t;
int A[N];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll c = gcd(a, b);
    return a * b / c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    ll cur = 1;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cur = lcm(cur,  A[i] / 2);
        if (cur > m) {
            cout << 0 << endl;
            exit(0);
        }
    }
    // check
    for (int i = 0; i < n; ++i) {
        int d = cur / (A[i] / 2);
        if (d % 2 == 0) {
            cout << 0 << endl;
            exit(0);
        }
    }

    cout << (m / cur + 1) / 2 << endl;


    return 0;
}

