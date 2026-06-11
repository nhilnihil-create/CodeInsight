#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr ll MOD = 1e9 + 7;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> s(1 << n), v(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        cin >> s[i];
    }
    sort(all(s), greater<int>());
    v[0] = 1;
    vector<int> vv;
    vv.push_back(s[0]);
    for (int i = 0; i < n; i++) {
        int id = 0;
        sort(all(vv), greater<int>());
        for (int j = 0; j < (1 << i); j++) {
            while (id < (1 << n) && (v[id] || vv[j] <= s[id])) {
                id++;
            }
            if (id == (1 << n)) {
                cout << "No" << endl;
                return 0;
            }
            vv.push_back(s[id]);
            v[id] = 1;
        }
    }
    cout << "Yes" << endl;
}