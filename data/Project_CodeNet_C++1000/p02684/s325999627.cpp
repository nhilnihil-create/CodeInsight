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
/* main */
int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<int> nextTown(n + 1);
    for (int i = 1; i <= n; i++) cin >> nextTown[i];

    vector<int> visited(n + 5, NIL), town(n + 5, 0);
    ll loopSize = 0, beforeLoop = 0;
    int t = 1;  // start: town-1
    visited[t] = 0;
    town[0] = t;
    for (int cnt = 1; cnt <= n; cnt++) {
        t = nextTown[t]; // 移動
        if (visited[t] != NIL) {
            loopSize = cnt - visited[t];
            beforeLoop = visited[t];
            break;
        }
        town[cnt] = t;
        visited[t] = cnt;
    }
    if (k <= beforeLoop) {
        cout << town[k] << '\n';
    }
    else {
        ll loopRest = (k - beforeLoop) % loopSize;
        cout << town[beforeLoop + loopRest] << '\n';
    }
}
