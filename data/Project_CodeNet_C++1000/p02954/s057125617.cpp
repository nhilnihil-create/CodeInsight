#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int NIL = -1;
const int MAX = 10000;
const int MOD = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
void solve_dubling() {
    // 10^5回後の移動先がわかれば良い
    // 偶数回移動でループするので
    // 10^100 = 10^5となる
    // Doublingで移動先を求める
    string S;
    cin >> S;

    int n = S.size();
    int MAXD = log2(1e+5 + 5);
    vector<vector<int>> to(MAXD + 1, vector<int>(n));
    // init
    // S[i] = R -> i + 1へ移動
    // S[i] = L -> i - 1へ移動
    for (int i = 0; i < n; i++) {
        if (S[i] == 'R') to[0][i] = i + 1;
        else to[0][i] = i - 1;
    }

    for (int d = 0; d < MAXD; d++) {
        for (int i = 0; i < n; i++) {
            to[d + 1][i] = to[d][to[d][i]];
        }
    }

    int k = 1e+5;
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        int x = i;
        for (int d = MAXD; d >= 0; d--) {
            int b = 1 << d;
            if (k & b) x = to[d][x];
        }
        cnt[x]++;
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << cnt[i];
    }
    cout << '\n';
}
/* main */
int main(){
    solve_dubling();
}
