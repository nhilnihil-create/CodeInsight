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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    VP a(n);
    REP(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(ALL(a), greater<P>());

    REP(i, n) {
        if (i == a[0].second)
            cout << a[1].first << ln;
        else
            cout << a[0].first << ln;
    }

    return 0;
}
