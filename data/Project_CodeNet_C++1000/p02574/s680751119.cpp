#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class Prime {
    vector<int> prime;
    vector<int> D;
    int N;

public:
    Prime(int N) : N(N), D(N + 1) {
        for (ll i = 2; i <= N; ++i) {
            if (D[i] == 0) {
                D[i] = i;
                prime.emplace_back(i);
            }
            for (auto &p : prime) {
                if (p > D[i] || i * p > N) break;
                D[i * p] = p;
            }
        }
    }
    vector<P> fact(int n) {
        vector<P> f;
        while (n > 1) {
            if (f.empty() || f.back().first != D[n]) {
                f.emplace_back(D[n], 1);
            } else {
                f.back().second++;
            }
            n /= D[n];
        }
        return f;
    }
    vector<int> get() { return prime; }
    bool is_prime(int n) { return n >= 2 && n == D[n]; }
};

class Main {
    int N;
    vector<int> A;
    ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
    void input() {
        cin >> N;
        A.resize(N);
        REP(i, N) { cin >> A[i]; }
    }
    void output() {
        ll g = A[0];
        REP(i, N - 1) { g = gcd(g, A[i + 1]); }
        if (g > 1) {
            cout << "not coprime" << endl;
            return;
        }
        set<ll> st;
        Prime prime(1000000);
        REP(i, N) {
            auto f = prime.fact(A[i]);
            for (auto &p : f) {
                if (st.count(p.first)) {
                    cout << "setwise coprime" << endl;
                    return;
                }
                st.emplace(p.first);
            }
        }
        cout << "pairwise coprime" << endl;
    }

public:
    Main() {
        input();
        output();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Main();

    return 0;
}
