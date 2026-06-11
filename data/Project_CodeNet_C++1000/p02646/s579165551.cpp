#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    LL A, V, B, W, T;
    scanf("%lld %lld %lld %lld %lld", &A, &V, &B, &W, &T);
    
    // 2. 捕まるかチェック.
    bool ok = false;
    LL xDiff = abs(A - B);
    if(V > W){
        LL vDiff = V - W;
        if(vDiff * T >= xDiff) ok = true;
    }
    
    // 3. 出力.
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
    
}