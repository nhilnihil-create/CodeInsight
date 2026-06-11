#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
const int N = 2e3 + 100;
pii p[N];
int n;

bool cmp(pii a, pii b) {
    return a.first > b.first;
}

ll dp[N][N];

ll clac(int cnt, int l, int r) {
    if (l > r)return 0;
    if (~dp[l][r])return dp[l][r];
    ll ans = 1ll * p[cnt].first * abs(p[cnt].second - l) + clac(cnt + 1, l + 1, r);
    ans = max(ans, 1ll * p[cnt].first * abs(p[cnt].second - r) + clac(cnt + 1, l, r - 1));
    return dp[l][r] = ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        p[i] = {x, i};
    }
    sort(p + 1, p + n + 1, cmp);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", clac(1, 1, n));
    return 0;
}
