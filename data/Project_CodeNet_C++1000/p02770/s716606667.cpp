// 解き直し.
// https://atcoder.jp/contests/abc156/tasks/abc156_f
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
LL d[5050], dMod[5050];

int main(){
    
    // 1. 入力情報.
    int k, q;
    scanf("%d %d", &k, &q);
    rep(i, k) scanf("%lld", &d[i]);
    
    // 2. クエリに回答(解説通り).
    rep(i, q){
        LL n, x, m, s = 0, t = 0;
        scanf("%lld %lld %lld", &n, &x, &m);
        
        // 2-1. d の 要素 を m で 割った余りで置き換える.
        rep(j, k) dMod[j] = d[j] % m;
        
        // 2-2. (a[i] mod m) == (a[i + 1] mod m) となる場合.
        rep(j, k){
            // if(dMod[j] % k == 0){ // 誤答となるっぽい.
            if(dMod[j] == 0){
                LL q = (n - 1) / k;
                LL r = (n - 1 - j) - q * k;
                s += (q + (r > 0));
            }
        }
        
        // 2-3. (a[i] mod m) > (a[i + 1] mod m) となる場合.
        // a[n - 1] を m で 割った商 から a[0] を m で 割った商 を 引く.
        // ex.
        // k = 5, n = 12
        // i = 0 1 2 3 4 5 6 7 8 9 10 11 (= n - 1)
        // a[0]  = x
        // a[1]  = x + 1 * d[0]
        // a[2]  = x + 1 * d[0] + 1 * d[1]
        // a[3]  = x + 1 * d[0] + 1 * d[1] + 1 * d[2]
        // a[4]  = x + 1 * d[0] + 1 * d[1] + 1 * d[2] + 1 * d[3]
        // a[5]  = x + 1 * d[0] + 1 * d[1] + 1 * d[2] + 1 * d[3] + 1 * d[4]
        // a[6]  = x + 2 * d[0] + 1 * d[1] + 1 * d[2] + 1 * d[3] + 1 * d[4]
        // a[7]  = x + 2 * d[0] + 2 * d[1] + 1 * d[2] + 1 * d[3] + 1 * d[4]
        // a[8]  = x + 2 * d[0] + 2 * d[1] + 2 * d[2] + 1 * d[3] + 1 * d[4]
        // a[9]  = x + 2 * d[0] + 2 * d[1] + 2 * d[2] + 2 * d[3] + 1 * d[4]
        // a[10] = x + 2 * d[0] + 2 * d[1] + 2 * d[2] + 2 * d[3] + 2 * d[4]
        // a[11] = x + 3 * d[0] + 2 * d[1] + 2 * d[2] + 2 * d[3] + 2 * d[4]
        t = x;
        rep(j, k){
            LL q = (n - 1) / k;
            LL r = (n - 1 - j) - q * k;
            LL u = (q + (r > 0)) * dMod[j];
            t += u;
        }
        // printf("s=%lld t=%lld n=%lld\n", s, t, n);
        t /= m;       // (a[n - 1] / m) を 計算.
        t -= (x / m); // (a[0] / m) を マイナス.
        
        // 2-4. (n - 1) から, 前項までの結果をマイナス.
        LL ans = (n - 1) - (s + t);
        printf("%lld\n", ans);
    }
    return 0;
    
}