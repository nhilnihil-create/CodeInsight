#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
const lint MOD = 1e9+7;
int main() {
    lint n,k; cin >> n >> k;
    lint a[2000];
    rep(i,n) cin >> a[i];
    lint an1 = 0;
    lint an2 = 0;
    rep(i,n) {
        rep(j,n) {
            if (i == j) continue;
            if (i < j && a[i] > a[j]) an2 ++;
            if (a[i] > a[j]) an1 ++;
        }
    }
    lint ans = (k*an2)%MOD;
    ans += an1*(((k*(k-1))/2)%MOD);
    ans = ans % MOD;
    cout << ans << endl;
}