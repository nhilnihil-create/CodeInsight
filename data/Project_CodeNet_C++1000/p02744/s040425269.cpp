#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n;
set<string> S;
void rec (int i, string s) {
    if (s.size() == n) {
        S.insert (s);
        return;
    }
    rep (j, 0, i + 2) {
        s += ('a' + j);
        // cout << s << "\n";
        rec (max (i, j), s);
        s.erase (s.size() - 1);
    }
}
int main() {
    string s = "a";
    cin >> n;
    rec (0, s);
    for (auto p : S) {
        cout << p << "\n";
    }
}