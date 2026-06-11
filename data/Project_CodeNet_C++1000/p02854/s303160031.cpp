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
    cin >> n;
    vector<ll> L(n);
    for (ll &l : L) cin >> l;

    ll ans = LINF, sum_back = accumulate(L.begin(), L.end(), 0LL);
    ll sum_front = 0;
    for (int i = 0; i < n - 1; i++) {
        sum_front += L[i];
        sum_back -= L[i];
        ans = min(ans, abs(sum_front - sum_back));
    }
    cout << ans << '\n';
}
