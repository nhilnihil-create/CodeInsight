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
    int N, T;
    cin >> N >> T;
    vector<pii> v(N);
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v[i] = pii(a, b);
    }
    sort(v.begin(), v.end());
    vector<int> dp(T+1);
    for (int i = 0; i < N; i++) {
        for (int j = T - 1; j >= 0; j--) {
            int k = min(T, j + v[i].first);
            dp[k] = max(dp[k], dp[j] + v[i].second);
        }
    }
    cout << dp[T] << '\n';
}