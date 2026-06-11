/*
[ ( ^ _ ^ ) ]
*/
// problem: atc/abc163_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000

void maxself(ll &a, ll b) {
    a = max(a, b);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<ll, int>> a(n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i].first);
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pair<ll, int>>());
    ll dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++) {
        for(int l=0; l<=i; l++) {
            int r = i - l;
            maxself(dp[l+1][r], dp[l][r] + a[i].first * abs(l - a[i].second));
            maxself(dp[l][r+1], dp[l][r] + a[i].first * abs(n-1-r - a[i].second));
        }
    }
    ll mx = 0;
    for(int l=0; l<=n; l++) {
        int r = n - l;
        maxself(mx, dp[l][r]);
    }
    printf("%lld\n", mx);
}
