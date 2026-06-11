#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int mod = 998244353;
int n, s, dp[6005], x;
vector<int> v;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> s;
    dp[0] = 1;

    while(n--) {
        cin >> x;
        for(int i = s; i >= 0; i--) {
            (dp[i + x] += dp[i]) %= mod;
            dp[i] *= 2;
            dp[i] %= mod;
        }
    }
    cout << dp[s];
}