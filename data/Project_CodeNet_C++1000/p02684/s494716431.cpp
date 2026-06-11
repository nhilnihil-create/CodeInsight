#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    ll now = 0;
    ll repeatStartIndex;
    ll repeatCycle;
    vector<ll> firstVisitIndex(n, -1);
    firstVisitIndex[now] = 0;
    for (ll i = 1; i <= n; i++) {
        now = a[now];
        if (firstVisitIndex[now] == -1) {
            firstVisitIndex[now] = i;
        }
        else {
            repeatStartIndex = now;
            repeatCycle = i - firstVisitIndex[now];
            break;
        }
    }
    ll ans;
    ll mod;
    if (k < firstVisitIndex[repeatStartIndex]) {
        now = 0;
        for (ll i = 0; i < k ; i++) {
            now = a[now];
        }
        ans = now;
    }
    else { // firstVisitIndex[repeatStartIndex] <= k
        k -= firstVisitIndex[repeatStartIndex];
        now = repeatStartIndex;
        mod = k % repeatCycle;
        for (ll i = 0; i < mod; i++) {
            now = a[now];
        }
        ans = now;
    }
    cout << ans + 1<< endl;
    return 0;
}