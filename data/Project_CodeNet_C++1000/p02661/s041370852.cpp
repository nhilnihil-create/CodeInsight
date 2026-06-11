#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll IINF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a, a + n); sort(b, b + n);
    if (n & 1) {
        cout << b[n / 2] - a[n / 2] + 1 << '\n';
    } else {
        cout << b[n / 2] + b[n / 2 - 1] - a[n / 2] - a[n / 2 - 1] + 1<< '\n';
    }
    return 0;
}