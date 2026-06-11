#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> a(n); REP(i, n) cin >> a[i];
    ll sum = 0; REP(i, n) sum += a[i];

    ll tmp = 0; int j = 0;
    while(tmp + a[j] <= sum / 2) {
        tmp += a[j]; ++j;
    }
    ll tmp2 = tmp + a[j];

    cout << min(sum - tmp * 2, tmp2 * 2 - sum) << endl;

    return 0;
}