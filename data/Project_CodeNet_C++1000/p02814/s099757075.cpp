#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) {
    if (y == 0)
        return x;
    else 
        return gcd(y, x%y);
}

ll lcm(ll x, ll y) {
    ll g = gcd(x, y);
    return x / g * y;
}

int main() {
    ll N, M;   cin >> N >> M;
    ll *A = new ll[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] /= 2;
    }

    vector<ll> p(N, 0);
    for (int i = 0; i < N; i++) {
        ll x = A[i];
        while (x % 2 == 0) {
            p[i]++;
            x /= 2;
        }
    }

    bool flag = true;
    for (int i = 0; i < N-1; i++) {
        if (p[i] != p[i+1])
            flag = false;
    }
    if (!flag) {
        cout << 0 << endl;
        return 0;
    }

    ll l = A[0];
    for (int i = 1; i < N; i++) {
        l = lcm(l, A[i]);
    }

    cout << ((M/l)+1)/2 << endl;

    return 0;
}