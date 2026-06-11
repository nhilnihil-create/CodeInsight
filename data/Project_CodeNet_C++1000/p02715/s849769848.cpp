#include<iostream>
using namespace std;

typedef long long ll;

const int MAX_N = 100005;
const ll M = 1000000007;

ll pot(ll x, ll y) {
    ll w = 1;

    while(y > 0) {
        if(y % 2 == 1) {
            w = (w * x) % M;
        }
        x = (x * x) % M;
        y /= 2;
    }

    return w;
}

ll T[MAX_N];

int main() {
    ll n, k;
    cin >> n >> k;

    ll w = 0;
    for(int i = k; i >= 1; i--) {
        T[i] = pot(k / i, n);
        for(int j = 2 * i; j <= k; j+=i) {
            T[i] -= T[j];
            T[i] += M;
            T[i] %= M;
        }
        w += (T[i] * i);
        w %= M;
    }

    cout << w;

    return 0;
}