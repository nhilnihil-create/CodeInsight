#include <bits/stdc++.h>

const int N = 200010;

char s[N];
int pre[N], pre1[N];

int main(){
    int n;
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + (s[i] == 'R');
        pre1[i] = pre1[i - 1] + (s[i] == 'W');
    }
    int ans = INT_MAX;
    for (int i = 0; i <= n; ++ i){
        int x1 = pre1[i];
        int x2 = pre[n] - pre[i];
        ans = std::min(ans, x1 + x2 - std::min(x1, x2));
    }
    printf("%d\n", ans);
    return 0;
}