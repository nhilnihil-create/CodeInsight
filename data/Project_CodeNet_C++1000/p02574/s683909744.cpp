#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
#define MAX 1000000

ll N;
vector<bool> IsPrime;
vector<ll> D(MAX, 0);

void eratos() {
    if (MAX + 1 > IsPrime.size()) IsPrime.resize(MAX + 1, true);
    IsPrime[0] = false;
    IsPrime[1] = false;

    for (size_t i = 2; i * i < MAX; i++) {
        if (IsPrime[i]) {
            for (size_t j = 2; i * j < MAX; j++) IsPrime[i * j] = false;
        }
    }
}

vector<P> prime_factorize(ll a) {
    vector<P> res;
    for (size_t i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        ll ex = 0;

        while (a % i == 0) {
            ex++;
            a %= i;
        }
        res.push_back({i, ex});
    }
    if (a != 1) res.push_back({a, 1});
    return res;
}


void prime_func(ll a) {
    for (size_t i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        ll ex = 0;
        while (a % i == 0) {
            ex++;
            a /= i;
        }
        D.at(i) += 1;
    }
    if (a != 1) D.at(a) += 1;
    return;
}

ll gcd (ll a, ll b) {
    if (b > a) {
        ll tmp = b;
        b = a;
        a = tmp;
    }
    if (b == 0) return a;
    return gcd(b, a % b);
}

string solve(vector<ll> A) {
    //string ans;
    //if (N + 1 > D.size()) D.resize(N + 1, 0);
    for (size_t i = 0; i < N; i++) prime_func(A.at(i));
    for (size_t i = 0; i < MAX; i++) {
        if (D.at(i) > 1) break;
        if (i >= MAX - 1) return "pairwise coprime";
    }
    ll gcd_value = A.at(0);
    for (size_t i = 1; i < N; i++) gcd_value = gcd(gcd_value, A.at(i));
    if (gcd_value == 1) return "setwise coprime";
    return "not coprime";
}

int main(){
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    cout << solve(A) << endl;
    return 0;
}
