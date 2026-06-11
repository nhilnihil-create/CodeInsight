#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    ll N, A, B;
    cin >> N >> A >> B;

    if ((B - A) % 2 == 0) {
        cout << (B - A) / 2 << '\n';
    }
    else {
        // 1 <- A: A - 1
        // 1 <- 1: 1
        // A -><- B: (B - A) / 2
        ll c1 = A + (B - A) / 2;
        // B -> N: N - B
        // N -> N: 1
        // A -><- B: (N - (N - B + 1 + A)) / 2 = (B - A - 1) / 2
        ll c2 = N - B + 1 + (B - A - 1) / 2;
        cout << min(c1, c2) << '\n';
    }
}
