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

using namespace std;

typedef long long ll;
typedef long double ld;

//#define int ll
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
#define mkt make_tuple
#define no {cout << "No"; return;}

vector <int> z_f(string s) {
    int n = s.length(), L = 0, R = 0;
    s += ".";
    vector <int> z(n);
    loop1(i, n - 1) {
        z[i] = max(0, min(R - i, z[i - L]));
        while (s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > R) {
            L = i;
            R = i + z[i];
        }
    }
    return z;
}

void solve() {
    int n, ans = 0; cin >> n;
    string s; cin >> s;
    loop(i, n) {
        vector <int> z = z_f(s);
        loop(j, z.size())
            ans = max(ans, min(z[j], j));
        s.erase(s.begin());
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}