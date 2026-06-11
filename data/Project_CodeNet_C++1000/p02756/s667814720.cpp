#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <numeric>
#include <ctime>
#include <complex>
#include <bitset>
#include <random>
#include <climits>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define double ld
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define F first
#define S second
#define pb push_back
#define pi pair <int, int>
#define all(x) begin(x), end(x)
#define ti tuple <int, int, int>
#define Point Vect
#define no {cout << -1; return;}
#define yes {cout << "Yes"; return;}
#define mkp make_pair
#define mkt make_tuple
#define cerr if(0) cerr

void solve() {
    string ss;
    deque <char> s;
    bool rev = 0;
    cin >> ss;
    for (char c : ss)
        s.pb(c);
    int q; cin >> q;
    loop(i, q) {
        int t; cin >> t;
        if (t == 1)
            rev = !rev;
        else {
            int f; char c;
            cin >> f >> c;
            if ((f == 1 && !rev) || (f == 2 && rev))
                s.push_front(c);
            else
                s.push_back(c);
        }
    }
    while (!s.empty()) {
        if (!rev) {
            cout << s.front(); s.pop_front();
        }
        else {
            cout << s.back(); s.pop_back();
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
