#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

ll dp[305][305][305];

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> h(n), v;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        v.push_back(h[i]);
    }
    v.push_back(0);
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    for (int i = 0; i < v.size(); i++) {
        mp[v[i]] = i;
    }

    ll INF = 2e18;
    for (int i = 0; i <= 300; i++) {
        for (int j = 0; j <= 300; j++) {
            for (int p = 0; p <= 300; p++) dp[p][i][j] = INF;
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < v.size(); p++) {
                dp[i + 1][j][p] = min(dp[i + 1][j][p], dp[i][j][p]);
                if (mp[h[i]] > p) {
                    dp[i + 1][j + 1][mp[h[i]]] = min(dp[i + 1][j + 1][mp[h[i]]], dp[i][j][p] + h[i] - v[p]);
                }
                else {
                    dp[i + 1][j + 1][mp[h[i]]] = min(dp[i + 1][j + 1][mp[h[i]]], dp[i][j][p]);
                }
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < v.size(); i++) {
        ans = min(ans, dp[n][n - k][i]);
    }
    cout << ans << endl;

    /*
    for (int i = 0; i <= n; i++) {
        cout << i << endl;
        for (int j = 0; j <= n; j++) {
            for (int p = 0; p < v.size(); p++) cout << dp[i][j][p] << " ";
            cout << endl;
        }
    }*/

    


}
