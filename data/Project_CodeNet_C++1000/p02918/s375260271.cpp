#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    int cnt = 0;
    rep(i, n-1) if (s[i] != s[i+1]) cnt++;

    int res = n-1-max(0, cnt - 2 * k);

    cout << res << endl;
    return 0;
}