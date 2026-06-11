#include <bits/stdc++.h>
#define pb push_back
#define pll pair <ll, ll>
#define mp make_pair
#define pyshnapyshnakaa ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define x first
#define y second
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
// #pragma GCC optimize("avx2")
// #pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse4.2")
#define plll pair <pair <ll, ll>, ll>
#define pllll pair <pair <ll, ll>, pair <ll, ll> >
#define psl pair <string, ll>
#define all(a) a.begin(), a.end()

typedef long long ll;

typedef long double ld;

using namespace std;

const ll maxn = 1e6 + 100;

ll n, m, v, p;

vector <ll> A;

bool check(ll i) {
    if (A[i] + m < A[p - 1]) {
        return 0;
    }
    ll split = m * v - m * (p - 1) - m;
    ll top = A[i] + m;
    ll q;
    for (q = p - 1; q < n; q++) {
        if (q == i) {
            continue;
        }
        split -= min(m, top - A[q]);
    }
    return split <= 0;
}

int main() {
    pyshnapyshnakaa;
    ll q, w, e, a, b, c;
    cin >> n >> m >> v >> p;
    A.resize(n);
    for (q = 0; q < n; q++) {
        cin >> A[q];
    }
    sort(all(A));
    reverse(all(A));
    ll L = -1, R = n, M;
    while (R - L > 1) {
        M = (L + R) / 2;
        if (check(M)) {
            L = M;
        }
        else {
            R = M;
        }
    }
    cout << L + 1;;
    return 0;
}
