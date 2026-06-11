/*
https://atcoder.jp/contests/abc176/tasks/abc176_c
*/

#include<bits/stdc++.h>
using namespace std;

bool db = false;
typedef long long LL;
typedef long double LD;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<LL, pll> pl_ll;
typedef pair<pll, LL> pll_l;

const LL INF = 1e18+1;

const LL maxn = 2*1e6+1;

LL t, n, m;
LL a[maxn+1];

int main() {

#ifdef MY_FILE_INPUT
    db = false;
    db = true;
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1]) {
            ans += (a[i-1] - a[i]);
            a[i] = a[i-1];
        }
    }
    cout << ans << endl;

    return 0;
}