#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF = 1e13;

vector<ll> fact(9);
void init_fact() {
    fact[0] = fact[1] = 1;
    for(ll i = 2; i < fact.size(); ++i) {
        fact[i] = i * fact[i - 1];
    }
}

ll N;
vector<ll> P, Q;

ll od(vector<ll> num, ll i, ll bit_flag) {
    if(i == N - 1) {
        return 1;
    }

    ll s_od = num[i];
    REP(j, num[i]) {
        if(bit_flag & (1 << j)) {
            --s_od;
        }
    }
    
    ll ans = (s_od - 1) * fact[N - i - 1];
    bit_flag |= 1 << num[i];
    return ans + od(num, i + 1, bit_flag);
}

int main() {
    init_fact();

    cin >> N;

    P.resize(N);
    Q.resize(N);
    REP(i, N) {
        cin >> P[i];
    }
    REP(i, N) {
        cin >> Q[i];
    }

    ll resP = od(P, 0, 0);
    ll resQ = od(Q, 0, 0);
    cout << abs(resP - resQ) << endl;

    return 0;
}