#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define inv(n, a) for(int i = 0; i < n; i++) cin >> a[i]
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int main() {
    int n; cin >> n;
    vector<int> x(n), l(n);
    vector<pair<int, int>> st;
    rep(i, n) {
        cin >> x[i] >> l[i];
        int s = x[i]-l[i];
        int t = x[i]+l[i];
        st.emplace_back(make_pair(s, t));
    }
    sort(st.begin(), st.end(), [](const auto &a, const auto &b){return a.second < b.second;});
    int cur = -INF, ans = 0;
    rep(i, n){
        if(cur <= st[i].first){ // 現在位置が i の左側範囲の外である
            ans++;
            cur = st[i].second; // i を残すと決めたなら、位置を Ti へ
        }
    }
    cout << ans << endl;
    return 0;
}
