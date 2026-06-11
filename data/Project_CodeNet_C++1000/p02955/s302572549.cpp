#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int n, k;
int a[505];

vector<ll> divisor(ll n) {
    vector<ll> div;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n / i) div.push_back(n / i);
        }
    }
    return div;
}

bool f(ll x) {
    if (x == 1) return true;
    vector<ll> vec;
    for (int i = 0; i < n; i++) {
        vec.push_back(a[i] % x);
    }
    sort(vec.begin(), vec.end());
    ll l[n + 1], r[n + 1];
    l[0] = r[n] = 0;
    for (int i = 0; i < n; i++) l[i + 1] = l[i] + vec[i];
    for (int i = n - 1; i >= 0; i--) r[i] = (x - vec[i]) + r[i + 1];
    for (int i = 0; i < n; i++) {
        if (l[i] == r[i] && l[i] <= k) return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> div = divisor(sum);
    sort(div.begin(), div.end(), greater<ll>());
    for (auto x : div) {
        if (f(x)) {
            cout << x << endl;
            return 0;
        }
    }
}