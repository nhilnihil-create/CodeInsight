#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    vector<ll> a(n), cnt(n+1);
    for(int i=0; i<n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll sum = 0;
    for(int i=1; i<=n; i++) sum += cnt[i] * (cnt[i] - 1) / 2;
    for(int i=0; i<n; i++) {
        ll num = sum;
        num -= cnt[a[i]] * (cnt[a[i]] - 1) / 2;
        cnt[a[i]]--;
        num += cnt[a[i]] * (cnt[a[i]] - 1) / 2;
        cout << num << "\n";
        cnt[a[i]]++;
    }
}