#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (int)(b); --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> VP;
typedef vector<PL> VPL;
typedef vector<string> VS;

bool is_mon_inc(const VI& array) {
    int n = array.size();
    REP(i, n - 1) {
        if (array[i] > array[i + 1]) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    VI h(n);
    REP(i, n) cin >> h[i];

    FORR(i, n - 2, 0) if (h[i] > h[i + 1]) h[i]--;

    cout << (is_mon_inc(h) ? "Yes" : "No") << ln;
    return 0;
}
