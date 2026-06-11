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
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int K;
    cin >> K;

    // a[i] = (a[i-1] * 10 + 7) % K
    // a[i] == 0 <=> 77...7(i個) % K == 0
    // Kで割ったあまりは {0, ..., K - 1}のK通り
    // 鳩ノ巣原理よりK回調べれば全部のあまりを網羅できる
    // K+1回目は必ず同じあまりが出てくるのでそれ以降はループする
    int sevens = 7 % K;
    for (int i = 1; i <= K; i++) {
        if (sevens == 0) {
            cout << i << '\n';
            return 0;
        }
        sevens = (sevens * 10 + 7) % K;
    }
    cout << -1 << '\n';
}
