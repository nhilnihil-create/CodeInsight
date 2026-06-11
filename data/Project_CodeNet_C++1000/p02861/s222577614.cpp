#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    ll N;
    cin >> N;

    ll x[N], y[N];
    REP(i, N) {
        cin >> x[i] >> y[i];
    }

    vector<ll> one_case;
    REP(i, N) {
        one_case.emplace_back(i);
    }

    long double sum = 0;
    ll cnt = 0;
    do {
        ++cnt;
        REP(i, N - 1) {
            sum += sqrt(pow(x[one_case[i + 1]] - x[one_case[i]], 2) + pow(y[one_case[i + 1]] - y[one_case[i]], 2));
        }
    } while(next_permutation(one_case.begin(), one_case.end()));

    cout << fixed << setprecision(15) << sum / cnt << endl;

    return 0;
}