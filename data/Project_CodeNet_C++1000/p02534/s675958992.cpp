#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    int K;
    scanf("%d", &K);
    string ans = "";
    
    // 2. 'ACL' を K回 繰り返し.
    rep(i, K) ans += "ACL";
    
    // 3. 出力.
    printf("%s\n", ans.c_str());
    return 0;
    
}