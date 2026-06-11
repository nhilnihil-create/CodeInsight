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
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = accumulate(a.begin(), a.begin() + K, 0);
    cout << ans << '\n';
}
