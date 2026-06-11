#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;
    vector<int> s(n + 1);
    rep(i, n) {
        s[i+1] = (s[i] + a[i]) % k;
    }

    map<int, int> mp;
    ll ans = 0;
    queue<int> q;
    rep(j, n + 1) {
        ans += mp[s[j]];
        mp[s[j]]++;
        q.push(s[j]);
        while (q.size() >= k) {
            mp[q.front()]--;
            q.pop();
        }
    }

    cout << ans << endl;
    return 0;
}