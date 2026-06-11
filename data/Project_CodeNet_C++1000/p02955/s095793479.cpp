#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int i = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define MP make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int MOD = 1e9 + 7;

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(All(ret));
    return ret;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll sum = 0;
    rep(i, N) sum += A[i];
    vector<ll> divisors = divisor(sum);
    ll res = 1;
    for(ll d : divisors) {
        vector<ll> mods(N);
        vector<ll> inv(N);
        rep(i, N) { mods[i] = A[i] % d; }
        sort(All(mods));
        rep(i, N) { inv[i] = d - mods[i]; }

        vector<ll> rsum(N + 1), lsum(N + 1);
        rep(i, N) rsum[i + 1] = rsum[i] + mods[i];
        for(int i = N - 1; i >= 0; i--)
            lsum[i] = lsum[i + 1] + inv[i];
        for(int i = 0; i < N + 1; i++) {
            if(abs(rsum[i] - lsum[i]) % d == 0) {
                if(max(rsum[i], lsum[i]) <= K)
                    res = max(d, res);
            }
        }
    }
    cout << res << endl;
    return 0;
}