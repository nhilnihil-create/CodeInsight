// ※※※ 解答不能 ※※※
// 以下のソースを勉強する.
// yutaka1999氏.
// https://atcoder.jp/contests/jsc2019-qual/submissions/7110919
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i + 1 < n; i++){
        for(int j = i + 1; j < n; j++){
            int x = i ^ j;
            int cnt = 0;
            while(x > 0){
                x /= 2;
                cnt++;
            }
            printf("%d ", cnt);
        }
        puts("");
    }
    return 0;
}