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
    int N, M, p, A = 0, W = 0;
    string J;
    cin >> N >> M;
    vector<int> AC(N), WA(N);
    rep(i, N) AC[i] = WA[i] = 0;
    rep(i, M) {
        cin >> p >> J;
        p--;
        if(J == "AC") {
            AC[p] = 1;
        } else if(!AC[p]) {
            WA[p]++;
        }
    }
    rep(i, N) {
        A += AC[i];
        if(AC[i]) W += WA[i];
    }
    cout << A << " " << W << endl;
}