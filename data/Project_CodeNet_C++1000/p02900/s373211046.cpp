#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // exponential

        // divide as much as you can
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // push the result
        res.push_back({a, ex});
    }

    // last num (if the lasting n is prime number and not 1)
    if (N != 1) res.push_back({N, 1});
    return res;
}

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}


int main() {
    ll a,b; cin >> a >> b;
    vector<pair<long long, long long> > p = prime_factorize(gcd(a,b));

    cout << p.size() + 1<< endl;

    return 0;
}
