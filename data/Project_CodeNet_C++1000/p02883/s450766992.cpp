#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

ll n, k;
vector<ll> a, f, af;

bool check(ll sec){
    ll tr = 0;
    for (int i = 0; i < n; ++i) {
        tr += max(0LL, ((af[i] - sec + f[i] - 1) / f[i]));
    }
    return tr <= k;
}

int main(){
    cin >> n >> k;
    a.assign(n, 0);
    f.assign(n, 0);
    af.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    sort(a.begin(), a.end());
    sort(f.begin(), f.end(), greater<ll>());

    for (int i = 0; i < n; ++i) {
        af[i] = a[i] * f[i];
    }

    ll left = -1;
    ll right = 1e12 + 10;

    while (right - left > 1) {
        ll mid = (right + left) / 2;

        if (check(mid)) right = mid;
        else left = mid;
    }
    cout << right << endl;
}