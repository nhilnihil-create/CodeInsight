#include <bits/stdc++.h>

using ll = long long;

int main(){
    int n;
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 1; i <= n; ++ i){
        ans += 1ll * i * (n - i + 1);
    }
    for (int i = 0; i < n - 1; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        if (u > v){
            std::swap(u, v);
        }
        ans -= 1ll * u * (n - v + 1);
    }
    printf("%lld\n", ans);
    return 0;
}