#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
ll M;
ll T;

void solve() {
    cin >> N >> M;
    T = 1;
    bool ok = true;
    set<ll> x;
    ll p, q;
    for (int i = 0; i < N; ++i) {
        ll a;
        cin >> a;
        ll b = a / 2;
        p = (-a) & a;
        if (i){
            if (p != q){
                ok = false;
                break;
            }
        }
        else q = p;
        T = T * b / __gcd(T, b);
    }
    if (ok) cout << ((M / T) + 1) / 2 << endl;
    else cout << 0 << endl;
}

int main() {
    solve();
    return 0;
}
