#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N;
    ll mini = LONG_LONG_MAX;
    vector<ll> L;
    cin >> N;
    L.resize(N);
    cin >> L[0];
    for(ll i = 1;i < N;i++) {
        ll temp;
        cin >> temp;
        L[i] = L[i - 1] + temp;
    }
    for(ll i = 0;i < N - 1;i++) {
        ll temp = abs(L.back() - 2 * L[i]);
        mini = min(mini, temp);
    }
    cout << mini << endl;
    return 0;
}
