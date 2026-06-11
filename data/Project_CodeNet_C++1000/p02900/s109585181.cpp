#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

void factorize(ll N, ll M, set<ll>& V) {
    ll L = gcd(N,M);
    M = L;
    for (ll i = 2; i * i <= L; i++) {
        if (M % i == 0) {
            V.insert(i);
            while (M % i == 0) M /= i;
        }
    }
    if (M != 1) V.insert(M);
}

int main() {
    ll A, B; cin >> A >> B;
    set<ll> VA;
    factorize(A, B, VA);
    cout << VA.size() + 1 << endl;
}
