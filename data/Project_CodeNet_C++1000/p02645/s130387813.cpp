#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back

int main(){
    
    // 1. 入力情報.
    char c[1010];
    scanf("%s", c);
    
    // 2. あだ名を作成.
    string ans = "";
    rep(i, 3) ans.pb(c[i]);
    
    // 3. 出力.
    printf("%s\n", ans.c_str());
    return 0;
    
}