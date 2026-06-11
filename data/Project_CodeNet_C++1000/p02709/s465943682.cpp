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

int n;
vi a, b;
vll2 cache;

ll dfs(int left, int right) {
    if (left > right) {
        return 0;
    }
    if (cache[left][right] != -1) {
        return cache[left][right];
    }
    int which = n - (right - left + 1);
    ll ans1 = dfs(left + 1, right) + abs(left - b[which]) * a[b[which]];
    ll ans2 = dfs(left, right - 1) + abs(right - b[which]) * a[b[which]];
    return cache[left][right] = max(ans1, ans2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    a = vi(n);
    loop(a) {
        cin >> x;
    }
    b = vi(n);
    rep(i, 0, n) {
        b[i] = i;
    }
    sort(all(b), [&](int x, int y) {
        return a[x] > a[y];
    });
    cache = vll2(n, vll(n, -1));
    cout << dfs(0, n - 1) << el;
}
