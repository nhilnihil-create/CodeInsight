#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    int X, Y;
    scanf("%d %d", &X, &Y);
    
    // 2. 賞金の合計額.
    int ans = 0;
    if(X <= 3) ans += 100000;
    if(Y <= 3) ans += 100000;
    if(X <= 2) ans += 100000;
    if(Y <= 2) ans += 100000;
    if(X == 1) ans += 100000;
    if(Y == 1) ans += 100000;
    if(X == 1 && Y == 1) ans += 400000;
    
    // 3. 出力.
    printf("%d\n", ans);
    return 0;
    
}