#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    char c[111];
    scanf("%s", c);
    int l = strlen(c);
    
    // 2. 判定.
    // 2-1. 文字列長が, 奇数の場合.
    if(l & 1){
        puts("No");
        return 0;
    }
    
    // 2-2. 文字列長が, 偶数の場合.
    bool ok = true;
    int at = 0;
    while(at < l){
        if(c[at] != 'h' || c[at + 1] != 'i'){
            ok = false;
            break;
        }
        at += 2;
    }
    
    // 3. 出力.
    printf("%s\n", ok ? "Yes" : "No");
    return 0;
    
}