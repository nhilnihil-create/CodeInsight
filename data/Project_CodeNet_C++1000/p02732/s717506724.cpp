#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, ans; ans = 0;
    scanf("%lld", &n);
    ll a[n] = {};
    ll memo[n+1] = {};
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        memo[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        ans += (memo[i]*(memo[i]-1))/2;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld\n", ans-(memo[a[i]]-1));
    }
}