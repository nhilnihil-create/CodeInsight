#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < n; i++)
#define debugA cerr << "AAAAA" << endl
#define debug_ cerr << "-------------" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                     \
    cout << #v << endl;                  \
    for (int i = 0; i < v.size(); i++) { \
        cout << v[i] << " ";             \
    }                                    \
    cout << endl;
#define debug_vec2(v)                           \
    cout << #v << endl;                         \
    for (int i = 0; i < v.size(); i++) {        \
        for (int j = 0; j < v[i].size(); j++) { \
            cout << v[i][j] << " ";             \
        }                                       \
        cout << endl;                           \
    }

template <typename T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
void quit(T a) {
    cout << a << endl;
    exit(0);
}

using Graph = vector<vector<int>>;
using P = pair<int, int>;
using P1 = pair<int, pair<int, int>>;  // クラスカル法とかで、{cost, {from,
                                       // to}}的に使う。
const ll LINF = 10010020030040056ll;
const int INF = 1001001001;
const double pi = acos(-1);

int main() {
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == t[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
