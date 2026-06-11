#include <bits/stdc++.h>

const int N = 5010;
using ll = long long;

int p[N], c[N];
bool vis[N];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &c[i]);
    }
    ll ret = LLONG_MIN;
    for (int i = 1; i <= n; ++ i){
        if (vis[i]){
            continue;
        }
        int x = i;
        std::vector<int> vec;
        while (!vis[x]){
            vec.emplace_back(c[x]);
            vis[x] = true;
            x = p[x];
        }
        ll sum = 0;
        for (auto u : vec){
            sum += u;
        }
        ll ans = 0;
        int sz = vec.size();
        int kk = k;
        if (sum > 0 && k / sz >= 3){
            int num = k / sz - 2;
            ans += num * sum;
            k -= num * sz;
            ret = std::max(ret, ans);
        }
        else if (sum <= 0){
            if (k > 2 * sz){
                k = k % sz + 2 * sz;
            }
        }
        ll max1 = LLONG_MIN;
        for (int j = 0; j < sz; ++ j){
            ll tot = 0;
            for (int u = 0; u < k; ++ u){
                tot += vec[(j + u) % sz];
                max1 = std::max(max1, tot);
            }
        }
        ans += max1;
        ret = std::max(ans, ret);
        k = kk;
    }
    printf("%lld\n", ret);
    return 0;
}