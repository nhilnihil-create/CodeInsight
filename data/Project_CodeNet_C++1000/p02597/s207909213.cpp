#include <cstdio>

char c[200000];

int main(){
    int n;
    int i;
    scanf("%d\n", &n);
    for(i = 0; i < n; ++i)
        scanf("%c", &c[i]);
    int l = 0, r = n - 1;
    int ans = 0;
    while(true){
        while(l < n && c[l] == 'R'){
            ++l;
        }
        if(l == n){
            printf("%d\n", ans);
            return 0;
        }
        while(r >= 0 && c[r] == 'W'){
            --r;
        }
        if(r == -1 || l > r){
            printf("%d\n", ans);
            return 0;
        }
        c[l] = 'R';
        c[r] = 'W';
        ++ans;
    }
    return 0;
}