#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Count(vec, x) count(vec.begin(), vec.end(), x)
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> primes;
    for (int i = 2; i <= sqrt(N); i++) {
        if (N % i) continue;
        int cnt = 0;
        while (N % i == 0) {
            cnt += 1;
            N /= i;
        }
        primes.push_back(make_pair(i, cnt));
    }
    if (N != 1) primes.push_back(make_pair(N, 1));
    // Rep(i, primes.size()) cout << primes[i].first << " " << primes[i].second << endl;
    int ans = 0;
    Rep(i, primes.size()) {
        int p = 1;
        while (primes[i].second >= p) {
            primes[i].second -= p;
            ans += 1;
            p += 1;
        }
    }
    cout << ans << endl;
    return 0;
}