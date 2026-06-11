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

int N;

void dfs(string &S, char l) {
    // dump(S);
    if (S.size() == N) {
        cout << S << endl;
        return;
    }

    for (char nxt = 'a'; nxt <= l + 1; nxt++) {
        S.push_back(nxt);
        dfs(S, max(nxt, l));
        S.pop_back();
    }
}

int main() {
    cin >> N;

    string S = "a";
    dfs(S, 'a');

    return 0;
}