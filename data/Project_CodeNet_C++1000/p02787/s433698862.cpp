#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
#include <iostream>
#include <vector>
using namespace std;

const int MAX_H = 11000;
int dp[MAX_H];

int main() {
    int H,n;
    cin >> H >> n;

    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];

    for (int h = 0; h < MAX_H; ++h) dp[h] = 1000000000; // INF
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int h = a[i]; h <= MAX_H; ++h) {
            dp[h] = min(dp[h], dp[h - a[i]] + b[i]);
        }
    }
    int ans=dp[H];
    for(int i=H;i<=10000;++i) ans=min(ans,dp[i]);
    cout << ans << "\n";
    return 0;
}