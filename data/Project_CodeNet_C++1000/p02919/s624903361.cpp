#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> P;
    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        P[p] = i;
    }

    ll ans = 0;
    multiset<int> L;
    L.insert(0);
    L.insert(0);
    L.insert(N + 1);
    L.insert(N + 1);
    for (int i = N; i >= 1; i--) {
        L.insert(P[i]);
        auto itr = L.lower_bound(P[i]);
        auto l1 = prev(itr);
        auto l2 = prev(l1);
        auto r1 = next(itr);
        auto r2 = next(r1);
        ll cnt = (*l1 - *l2) * (*r1 - *itr) + (*r2 - *r1) * (*itr - *l1);
        ans += cnt * i;
    }
    cout << ans << endl;
}
