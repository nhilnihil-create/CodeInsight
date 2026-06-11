#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long n, a, dp[2005][2005];
vector <pair<int, int> > v;

long long solve(int l, int r){
    if (~dp[l][r]) return dp[l][r];
    if (l > r) return dp[l][r] = 0;
    int idx = (r-l);
    return dp[l][r] = max(solve(l+1, r) + (long long)abs(v[idx].second-l)*v[idx].first , solve(l, r-1) + (long long)abs(r-v[idx].second)*v[idx].first);
}

int main() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++){
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    cout << solve(0, n-1) << "\n";
}
