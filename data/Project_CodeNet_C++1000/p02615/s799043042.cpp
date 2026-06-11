#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;
using ll = long long int;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll mod = 1000000007;

vector<ll> dp(400010);

int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end(),greater<int>());
    rep(i,n) dp[i] = a[i];
    ll ans = dp[0];
    for(int i = 1;i < (n - 1);i++) {
        int num = i + n/2 + n%2 - 1;
        ans += dp[i];
        dp[num] = dp[i];
    }
    cout << ans << endl;
}
