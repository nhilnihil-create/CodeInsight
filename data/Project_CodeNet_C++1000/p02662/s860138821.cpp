#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 3001;

int n, s, dp[N][N], mod = 998244353;
vector <int> a;

int solve(int idx, int sum){
    if(sum > s) return 0;
    if(idx == n) return sum == s;
    int &ret = dp[idx][sum];
    if(ret != -1) return ret;
    ret = 2 * solve(idx + 1, sum);
    if(ret >= mod) ret -= mod;
    ret += solve(idx + 1, sum + a[idx]);
    if(ret >= mod) ret -= mod;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> s;
    a.resize(n);
    for(auto &i : a) cin >> i;
    cout << solve(0, 0) << endl;
}
