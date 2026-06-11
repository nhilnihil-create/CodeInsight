#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;
template <typename A, size_t N, typename T> void Fill(A (&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
// long long mod = 998244353;
#define REP(i, n) for (long long i = 0; i < (n); i++)
#define rep(i, a, n) for (long long i = a; i < (n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
long long mod = 1000000007;
long long modpow(long long m, long long n, long long modvalue) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2, modvalue);
        return t * t % modvalue;
    } else {
        return modpow(m, n - 1, modvalue) * m % modvalue;
    }
}

long long moddiv(long long a, long long b, ll modvalue) { return (a * modpow(b, mod - 2, modvalue)) % modvalue; }

const ll INF = 1LL << 60;

string change_binary(long long a) {
    string ret;
    for (int i = 31; i >= 0; i--) {
        ret += (a >> i & 1) + '0';
    }
    return ret;
}

ll nCkmod(ll n, ll k, ll modvalue) {
    ll numera = 1;
    for (int i = n; i > n - k; i--) {
        numera *= i;
        numera %= modvalue;
    }
    ll denomi = 1;
    REP(i, k) {
        denomi *= (i + 1);
        denomi %= modvalue;
    }
    return moddiv(numera, denomi, modvalue);
}

map<ll, ll> cnt;
void primeFactors(long long n) {
    while (n % 2 == 0) {
        cnt[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            cnt[i]++;
            n = n / i;
        }
    }
    if (n > 2) {
        cnt[n]++;
    }
}
int main() {
    ll n, k;
    cin >> k;
    queue<ll> lunlun;
    lunlun.push(1);
    lunlun.push(2);
    lunlun.push(3);
    lunlun.push(4);
    lunlun.push(5);
    lunlun.push(6);
    lunlun.push(7);
    lunlun.push(8);
    lunlun.push(9);
    ll now = 0;
    rep(i, 1, 11) {
        ll n = lunlun.size();
        REP(j, n) {
            if (lunlun.front() % 10 != 0) {
                lunlun.push(lunlun.front() * 10 + lunlun.front() % 10 - 1);
            }
            lunlun.push(lunlun.front() * 10 + lunlun.front() % 10);
            if (lunlun.front() % 10 != 9) {
                lunlun.push(lunlun.front() * 10 + lunlun.front() % 10 + 1);
            }
            now++;
            // cout << lunlun.front() << endl;
            if (now == k) {
                cout << lunlun.front() << endl;
                return 0;
            }
            lunlun.pop();
        }
    }
}