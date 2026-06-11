// 20.txt, 21.txt で, WA版となったので修正.
// m[0] = -10000, m[1] = -10000 のようなテストケースで, WA となった.
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
    
    // 1. 入力情報取得.
    int N;
    scanf("%d", &N);
    int A[N];
    for(int i = 0; i < N; i++) scanf("%d", &A[i]);
    
    // 2. sort.
    sort(A, A + N);
    
    // 3. マイナス部分, プラス部分(※0含む) を 取得.
    vector<int> m, p;
    for(int i = 0; i < N; i++){
        if(A[i] < 0) m.pb(A[i]);
        else         p.pb(A[i]);
    }
    
    // 4. 操作列 の 特定.
    // 3-1. マイナス部分が, 無い場合.
    int ml = m.size(), pl = p.size();
    if(ml == 0){
        if(pl == 2){
            printf("%d\n", p[1] - p[0]);
            printf("%d %d\n", p[1], p[0]);
            return 0;
        }else{
            int M = p[0] - p[pl - 1];
            for(int i = 1; i < pl - 2; i++) M -= p[i];
            M = p[pl - 2] - M;
            printf("%d\n", M);
            int memo = p[0] - p[pl - 1];
            printf("%d %d\n", p[0], p[pl - 1]);
            for(int i = 1; i < pl - 2; i++){
                printf("%d %d\n", memo, p[i]);
                memo -= p[i];
            }
            printf("%d %d\n", p[pl - 2], memo);
            return 0;
        }
    }
    
    // 3-2. プラス部分が, 無い場合.
    if(pl == 0){
        if(ml == 2){
            printf("%d\n", m[1] - m[0]);
            printf("%d %d\n", m[1], m[0]);
            return 0;
        }else{
            int M = m[ml - 1] - m[0];
            for(int i = 1; i < ml - 1; i++) M -= m[i];
            printf("%d\n", M);
            int memo = m[ml - 1] - m[0];
            printf("%d %d\n", m[ml - 1], m[0]);
            for(int i = 1; i < ml - 1; i++){
                printf("%d %d\n", memo, m[i]);
                memo -= m[i];
            }
            return 0;
        }
    }
    
    // 3-3. マイナス部分, プラス部分が, 共に存在する場合.
    if(pl > 0 && ml > 0){
        if(pl == 1){
            int M = p[0];
            for(int i = 0; i < ml; i++) M -= m[i];
            printf("%d\n", M);
            int memo = p[0] - m[0];
            printf("%d %d\n", p[0], m[0]);
            for(int i = 1; i < ml; i++){
                printf("%d %d\n", memo, m[i]);
                memo -= m[i];
            }
            return 0;
        }else{
            int M = m[0] - p[0];
            for(int i = 1; i < pl - 1; i++) M -= p[i];
            M = p[pl - 1] - M;
            for(int i = 1; i < ml; i++) M -= m[i];
            printf("%d\n", M);
            int memo = m[0] - p[0];
            printf("%d %d\n", m[0], p[0]);
            for(int i = 1; i < pl - 1; i++){
                printf("%d %d\n", memo, p[i]);
                memo -= p[i];
            }
            printf("%d %d\n", p[pl - 1], memo);
            memo = p[pl - 1] - memo;
            for(int i = 1; i < ml; i++){
                printf("%d %d\n", memo, m[i]);
                memo -= m[i];
            }
            return 0;
        }
    }
    return 0;
    
}