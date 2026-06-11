#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
const long long INFLL = 1LL << 60;
const int INFINT = 1 << 30;
const long long MOD = 1e9 + 7;

int main() {
    int N, c = 0, p = 0, q = 0;
    cin >> N;
    vector<int> P(N), Q(N), R(N);
    rep(i, N) { cin >> P.at(i); }
    rep(i, N) { cin >> Q.at(i); }
    rep(i, N) { R.at(i) = i + 1; }

    do {
        if(P == R) p = c;
        if(Q == R) q = c;
        c++;
    } while(next_permutation(R.begin(), R.end()));

    cout << abs(p - q) << endl;
}
