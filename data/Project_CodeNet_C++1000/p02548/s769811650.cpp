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
    int n;
    cin >> n;

    int ans = 0;
    // A × B < N を満たす正整数の組 (A,B) に対し,
    // A × B + C = N となるような正整数Cはちょうど一つに定まります
    for (int i = 1; i < n; i++) {
        ans += (n - 1) / i;
    }
    cout << ans << '\n';
}
