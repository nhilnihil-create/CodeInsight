#include "bits/stdc++.h"

using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define lin "\n"
#define fast_io ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(0)
#define mod 1000000007
ll dp[2005];

void khelo() {
    dp[3] = dp[4] = dp[5] = 1;
    for (int i = 6; i <= 2000; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 3]) % mod;
    }
}

void solve() {
    int n;
    cin >> n;
    cout << dp[n];
}

int main() {
//        fast_io;
    khelo();
    int t = 1;
    //    cin >> t;
//    scanf("%d", &t);
    int c = 1;
    while (t--) {
//        printf("Case %lld:\n", c);
        //        cout<<"Case "<<c<<": ";
        solve();
        c++;
    }
}