#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int main(){
    LL ans = 0, u, v;
    scanf("%d", &n);
    for(LL i = 1; i <= n; i++){
        ans += i * (n - i + 1);
    }
    for(int i = 1; i < n; i++){
        scanf("%lld%lld", &u, &v);
        if(v < u) swap(u, v);
        ans -= u * (n - v + 1);
    }
    printf("%lld\n", ans);
    return 0;
}