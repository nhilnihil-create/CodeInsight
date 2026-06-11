// 解き直し.
// https://img.atcoder.jp/sumitrust2019/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){

    // 1. 入力情報.
    LL T1, T2, A1, A2, B1, B2;
    scanf("%lld %lld %lld %lld %lld %lld", &T1, &T2, &A1, &A2, &B1, &B2);
    
    // 2. 解説通り.
    // P = (A1 - B1) * T1, Q = (A2 - B2) * T2 と置いて場合分け.
    LL P = (A1 - B1) * T1, Q = (A2 - B2) * T2, ans = 0;
    
    // 2-1. P > 0 の 場合は, P, Q を -1倍.
    if(P > 0) P *= -1, Q *= -1;
    
    // 2-2. P + Q < 0.
    if(P + Q < 0){
        puts("0");
        return 0;
    }
    
    // 2-3. P + Q == 0.
    if(P + Q == 0){
        puts("infinity");
        return 0;
    }
    
    // 2-4. P + Q > 0.
    //  (kサイクル目)  ->     (P 進む)         ->  (Q 進む(= k + 1サイクル目))
    // k * (P + Q) > 0 -> k * (P + Q) + P < 0  -> (k + 1) * (P + Q) > 0   … 0 の 位置 を 2回通過.
    // k * (P + Q) > 0 -> k * (P + Q) + P == 0 -> (k + 1) * (P + Q) > 0   … 0 の 位置 を 1回通過.
    // k * (P + Q) > 0 -> k * (P + Q) + P > 0  -> (k + 1) * (P + Q) > 0   … 0 の 位置 を 0回通過.
    LL S = -P / (P + Q), T = -P % (P + Q);
    if(T != 0) printf("%lld\n", 2 * S + 1);
    else       printf("%lld\n", 2 * S);
    return 0;
    
}