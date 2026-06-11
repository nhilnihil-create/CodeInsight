#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;

struct child {
    ll aval, i;
};

struct child arr[2001];

bool comp(struct child a, struct child b) {
    if(a.aval == b.aval) return a.i < b.i;
    return a.aval > b.aval;
}

ll dp[2001][2001];

ll solve(int l, int r) {
    if(dp[l][r] != -1) {
        return dp[l][r];
    }
    int cur = l + r;
    if(cur >= N) return 0;
    ll left = arr[cur].aval * (arr[cur].i - l) + solve(l + 1, r);
    ll right = arr[cur].aval * (N - 1 - r - arr[cur].i) + solve(l, r + 1);
    return dp[l][r] = max(left, right);
}

int main() {
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; ++i) {
        cin >> arr[i].aval;
        arr[i].i = i;
    }
    sort(arr, arr + N, comp);
    cout << solve(0, 0) << "\n";
    return 0;
}
