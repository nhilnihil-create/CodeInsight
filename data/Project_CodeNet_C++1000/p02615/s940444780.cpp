#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    int left = n - 1;
    for (int i = n - 1; i >= 0; -- i){
        for (int j = 0; j < (i == n - 1 ? 1 : 2); ++ j){
            if (left){
                -- left;
                sum += a[i];
            }
        }
    }
    printf("%lld\n", sum);
    return 0;
}