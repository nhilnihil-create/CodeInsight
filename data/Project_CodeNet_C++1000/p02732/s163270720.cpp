#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll kaij(ll n) {
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 0;
    }
    return n*(n - 1);
}

int main() {
    ll N = 0;
    cin >> N;
    vector<ll> A(N,0);
    ll ans = 0;
    vector<ll> c(2*1e5 + 100, 0);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
        c.at(A.at(i))++;
    }
    for(ll i = 0; i < 2*1e5 + 10; i++) {
        if(c.at(i)) {
            ans += kaij(c.at(i))/2;
        }
    }
    //cout << ans << endl;
    for(ll i = 0; i < N; i++) {
        cout << ans - kaij(c.at(A.at(i)))/2 + kaij(c.at(A.at(i)) - 1)/2 << endl;
    }

    return 0;
}