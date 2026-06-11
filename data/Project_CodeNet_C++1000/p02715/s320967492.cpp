#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n , k , a[N];
int fp(int x , int y) {
    if(!y)
        return 1;
    int res = fp(x , y >> 1);
    res = (1ll * res * res) % mod;
    if(y & 1)
        res = (1ll * res * x) % mod;
    return res;
}
int main() {
    abdelrahman010
    cin >> n >> k;
    int ans = 0;
    for(int i = k;i >= 1;i--) {
        int cnt = fp(k / i , n);
        for(int j = i;j <= k;j += i)
            cnt = (cnt - a[j] + mod) % mod;
        a[i] = cnt;
        ans = (ans + (1ll * a[i] * i) % mod) % mod;
    }
    cout << ans;
    return 0;
}