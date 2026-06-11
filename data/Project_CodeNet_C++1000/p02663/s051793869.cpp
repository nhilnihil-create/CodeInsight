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
    int h1, h2, m1, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int M1 = h1 * 60 + m1, M2 = h2 * 60 + m2;
    int dif = M2 - M1;
    if (dif < 0) dif += 24 * 60;
    cout << max(dif - k, 0) << '\n';
}
