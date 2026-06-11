#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    fast_io
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int count = 0;
    rep(i,n-1) if (s[i] != s[i+1]) count++;
    int ans = n - count - 1;
    ans += 2*k;
    ans = min(n-1, ans);
    cout << ans << endl;
    return 0;
}