#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    reverse(all(s));
    int x = 1;
    int tot = 0;
    vector<int> cnt(2019);
    ll ans = 0;
    rep(i, n) {
        cnt[tot]++;
        tot += (s[i] - '0') * x;
        tot %= 2019;
        ans += cnt[tot];
        x = x * 10 % 2019;
    }
    cout << ans << endl;
    return 0;
}
