#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)

bool isPrime(ll X) {
    FOR(i, 2, X) {
        if(X % i == 0) return false;
    }
    return true;
}

int main() {
    ll X;
    cin >> X;

    while(!isPrime(X)) X++;
    cout << X << endl;

    return 0;
}