#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef std::pair<int, ll> pr;

int main(int, char**)
{
    int n;
    vector<pr> a;

    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a.push_back(make_pair(i+1, tmp));
    }
    sort(
        a.begin(),
        a.end(),
        [](const pr& x, const pr& y){ return x.second > y.second; }
    );

    int x, y;
    ll tmp1, tmp2;
    vector< vector<ll> > dp(n+1, vector<ll>(n+1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            x = j;
            y = i-j;
            tmp1 = tmp2 = 0LL;
            if (x > 0) tmp1 = dp[x-1][y] + a[i-1].second * abs(a[i-1].first - x); // 左詰め
            if (y > 0) tmp2 = dp[x][y-1] + a[i-1].second * abs(a[i-1].first - (n-y+1)); // 右詰め
            dp[x][y] = max(tmp1, tmp2);
        }
    }
    ll max = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[i][n-i] > max) max = dp[i][n-i];
    }

    cout << max << endl;

    return 0;
}