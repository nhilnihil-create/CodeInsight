#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

int main() {
    int M;
    ll D = 0, S = 0;
    cin >> M;
    REP(i, M) {
        ll d, c;
        cin >> d >> c;
        D += c;
        S += d * c;
    }
    cout << D - 1 + (S - 1) / 9 << endl;
    return 0;
}