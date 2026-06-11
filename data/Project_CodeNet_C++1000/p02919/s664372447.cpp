#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        m[p[i]] = i;
    }

    ll ans = 0;
    set<ll> fow, rev;
    fow.insert(-1);  fow.insert(n);
    rev.insert(-1);  rev.insert(n);
    for (int i = n - 1; i >= 0; i--) {
        fow.insert(m[i]);  rev.insert(n - 1 - m[i]);
        //if (i == n - 1) continue;
        ll a, b, c, d;
        c = *fow.upper_bound(m[i]);
        if (c == n) d = n;
        else d = *fow.upper_bound(c);
        b = n - 1 - *rev.upper_bound(n - 1 - m[i]);
        if (b == -1) a = -1;
        else a = n - 1 - *rev.upper_bound(n - 1 - b);
        ans += (i + 1) * ((b - a) * (c - m[i]) + (m[i] - b) * (d - c));
        /*
        cerr << i _ a _ b _ m[i] _ c _ d _ ans << endl;
        for (auto &i : fow) cerr << i;
        cerr << endl;
        for (auto &i : rev) cerr << i;
        cerr << endl;*/
    }
    cout << ans << endl;

}
