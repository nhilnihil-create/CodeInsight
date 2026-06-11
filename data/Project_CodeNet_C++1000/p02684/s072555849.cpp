#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int NIL = -1;
const int MAX = 200005;
const int MOD = 1000000007;
const double pi = 3.141592653589;
/* global variables */
int D = 60;
/* function */
/* main */
int main(){
    int n; ll k;
    cin >> n >> k;
    // Doublingでの解法
    // O(nlog(k))
    // to[l][i]: start i -> 2^l進んだ時の場所
    vector<vector<int>> to(D, vector<int>(MAX));
    for (int i = 0; i < n; i++) {
        cin >> to[0][i];
        to[0][i]--;
    }

    // i -> 2^{l + 1}進む
    // 2^l個次の要素」の2^l個次の要素は、2^(l+1)個次の要素
    // <=>   i  -> 1. 2^{l} 進む   -> 2. 2^{l}進む
    // 1. to[l][i]
    // 2. to[l][to[l][i]]
    // -> to[l + 1][i] = to[l][to[l][i]]
    for (int l = 0; l < D - 1; l++) {
        for (int i = 0; i < n; i++) {
            to[l + 1][i] = to[l][to[l][i]];
        }
    }

    int v = 0;
    for (int i = D - 1; i >= 0; --i) {
        ll b = 1LL << i;
        if (k & b) {
            //  二進展開して, k番目のビットが立っていたら,
            //  位置を2^iだけ次にずらす
            v = to[i][v];
        }
    }
    cout << v + 1 << '\n';
}
