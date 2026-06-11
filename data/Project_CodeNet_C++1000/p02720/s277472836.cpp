
#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const double EPS = 1e-10;

vector<lint> luns(0);

void dfs(string& X) {
    if (X.size() == 11) { return; }

    int prev = X.back() - '0';

    for (int x = 0; x < 10; x++) {
        if (abs(x - prev) > 1) continue;

        X.push_back('0' + x);
        luns.push_back(stoll(X));
        dfs(X);
        X.pop_back();
    }
}

int main() {
    lint K;
    cin >> K;

    string dummy = "";

    for (int x = 1; x < 10; x++) {
        string start = to_string(x);
        luns.push_back(stoll(start));
        dfs(start);
    }
    sort(luns.begin(), luns.end());
    // dump(luns);

    cout << luns[K - 1] << endl;

    return 0;
}