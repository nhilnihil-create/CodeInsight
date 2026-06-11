#include <bits/stdc++.h>

const int N = 7;

char s[N][N];

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    int cnt = 0;
    for (int i = 0; i < 1 << n; ++ i){
        for (int j = 0; j < 1 << m; ++ j){
            int ccnt = 0;
            for (int u = 0; u < n; ++ u){
                for (int v = 0; v < m; ++ v){
                    if (i >> u & 1){
                        continue;
                    }
                    if (j >> v & 1){
                        continue;
                    }
                    ccnt += s[u][v] == '#';
                }
            }
            cnt += ccnt == k;
        }
    }
    printf("%d\n", cnt);
    return 0;
}