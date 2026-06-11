#include <bits/stdc++.h>

#define ll long long int

using namespace std;

bool isGood(ll n, ll m, ll v, ll p, vector<ll> const & A, ll x) {
    if (x<p) return true;
    ll now = A[x] + m;
    if (A[p - 1] > now) return false;
    ll score = 0;
    score += (p-1) * m;
    score += (n-x) * m;
    for (ll i = p - 1; i < x; ++i) {
        score += min(m, max(0LL, now - A[i]));
    }
    return score >= m * v;
}

int main() {
    ll n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<ll> A(n);
    for (auto & a : A) cin >> a;
    sort(A.begin(), A.end(), greater<ll>());

    ll ok = -1;
    ll ng = n;

    while (abs(ng - ok) > 1) {
        ll mid = (ok+ng)/2;
        if (isGood(n,m,v,p,A,mid)) ok = mid;
        else ng = mid;
    }

    cout << ok+1 << endl;
}
