#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vi2;
typedef vector<vi2> vi3;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<vll> vll2;
typedef vector<vll2> vll3;
typedef vector<bool> vb;

#define el '\n'
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repi(i, a, b) for (int i = a; i >= b; i--)
#define umap unordered_map
#define uset unordered_set
#define vec vector
#define loop(a) for (auto &x : a)
#define all(a) a.begin(), a.end()
#define mp make_pair

const int INF = 1e7;

vi a;
int n;
vi2 cache;

void min_self(int &a, int b) {
    a = min(a, b);
}

int dfs(int which, int one_more) {
    if (which == n) {
        return one_more;
    }

    int &c = cache[which][one_more];
    if (c != -INF) {
        return c;
    }

    int digit = a[which];
    int ans = INF;
    if (one_more == 0) {
        min_self(ans, digit + dfs(which + 1, 0));
        min_self(ans, digit + 1 + dfs(which + 1, 1));
    } else {
        min_self(ans, 10 - digit + dfs(which + 1, 0));
        min_self(ans, 10 - digit - 1 + dfs(which + 1, 1));
    }

    return c = ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    n = s.size();
#ifdef LOCAL
    cout << "n:" << n << el;
#endif
    a = vi(n);
    rep(i, 0, n) {
        a[i] = s[i] - '0';
    }
    cache = vi2(n, vi(2, -INF));
    cout << min(1 + dfs(0, 1), dfs(0, 0)) << el;
}
