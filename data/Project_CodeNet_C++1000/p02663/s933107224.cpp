#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    int h1, m1, h2, m2, k;
    scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
    
    // 2. 時間帯の長さは？
    int ans = 60 * h2 + m2 - 60 * h1 - m1 - k;
    
    // 3. 出力.
    printf("%d\n", ans);
    return 0;
    
}