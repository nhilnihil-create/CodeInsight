#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    char c[202020];
    scanf("%s", c);
    int l = strlen(c);
    
    // 2. ? を 'D' に 置き換える.
    rep(i, l) if(c[i] == '?') c[i] = 'D';
    
    // 3. 出力.
    string ans(c);
    printf("%s\n", ans.c_str());
    return 0;
    
}