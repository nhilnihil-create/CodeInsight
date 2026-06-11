#include <bits/stdc++.h>
using namespace std;

int main() {
    int s; cin >> s;
    long long mod = pow(10, 9) + 7;
    vector<long long> dp = {0, 0, 0, 1};
    for (int i=4; i<=s; i++) dp.push_back((dp[i-1]+dp[i-3]) % mod);
    cout << dp[s] << endl;
}