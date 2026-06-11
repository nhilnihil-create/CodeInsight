#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) std::cout << x << endl;
#define println(x) std::cout << x << endl;
using namespace std;
// using namespace atcoder;


long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

// Eratosthenes
vector<ll> divTable;

void setupDivTable(ll n) {
    divTable.assign(n + 1, 0);
    divTable[0] = 1;
    divTable[1] = 1;
    for (ll i = 2; i <= n; i++) {
        if (divTable[i] == 0) {
            for (ll j = 1; i * j <= n; j++) {
                divTable[i * j] = i;
            }
        }
    }
}


vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    while (N > 1) {
        ll a = divTable[N];
        ll ex = 0; // 指数
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}


void Main()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    ll a = A[0];
    rep(i, n) {
        a = GCD(a, A[i]);
    }
    bool setwise = a == 1;

    ll maxA = *max_element(all(A));

    setupDivTable(maxA + 1);
    vector<ll> cnt(maxA + 1);
    rep(i, n) {
        auto primes = prime_factorize(A[i]);
        for (auto& p : primes) {
            cnt[p.first]++;
        }
    }

    bool pairwise = true;
    rep(i, cnt.size()) {
        if (cnt[i] >= 2) {
            pairwise = false;
            break;
        }
    }

    if (pairwise) { put("pairwise coprime") }
    else if (setwise) { put("setwise coprime") }
    else { put("not coprime") }

}
signed main(){ Main();return 0;}