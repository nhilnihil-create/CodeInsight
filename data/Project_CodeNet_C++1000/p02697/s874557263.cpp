// 解き直し.
// https://img.atcoder.jp/abc165/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    int N, M;
    scanf("%d %d", &N, &M);
    
    // 2. 解説通り.
    if(M & 1){
        rep(i, M / 2)     printf("%d %d\n", i + 1, M - i);
        rep(i, M / 2 + 1) printf("%d %d\n", M + 1 + i, 2 * M + 1 - i);
    }else{
        rep(i, M / 2) printf("%d %d\n", i + 1, M + 1 - i);
        rep(i, M / 2) printf("%d %d\n", M + 2 + i, 2 * M + 1 - i);
    }
    return 0;
    
}