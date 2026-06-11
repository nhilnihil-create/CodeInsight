#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int a[101010], b[101010];

int main(){
    
    // 1. 入力情報.
    int A, B, M, minA = 202020, minB = 202020;
    scanf("%d %d %d", &A, &B, &M);
    rep(i, A){
        scanf("%d", &a[i]);
        minA = min(minA, a[i]);
    }
    rep(i, B){
        scanf("%d", &b[i]);
        minB = min(minB, b[i]);
    }
    
    // 2. 購入金額の最小値は？
    int ans = minA + minB;
    rep(i, M){
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        x--;
        y--;
        ans = min(ans, a[x] + b[y] - c);
    }
    
    // 3. 出力.
    printf("%d\n", ans);
    return 0;
    
}