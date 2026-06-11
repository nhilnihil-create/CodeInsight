#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = pair<ii, int>;
#define vt vector
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 1e3 + 5;
const int M = 1e4 + 5;

int h, n;
int a[N], b[N];
int dp[N][M];

int f(int idx, int hp) {
    if(hp <= 0) return 0;
    if(idx > n) return INF;
    int &sol = dp[idx][hp];
    if(sol != -1) return sol;
    return sol = min(f(idx + 1, hp), f(idx, hp - a[idx]) + b[idx]);
}

void solve() {
    cin >> h >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << f(1, h) << "\n";
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}