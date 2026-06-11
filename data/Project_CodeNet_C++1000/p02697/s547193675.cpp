#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // 1とNが組む、２とN-1が組む・・・M/2を超えたら片方だけ一つ引いてXとN-Xが組む
    int N, M;
    cin >> N >> M;
    vector<P> ans;
    int low = 1, high = N;
    if (N&1) {
        rep(i, M) {
            ans.emplace_back(low, high);
            low++; high--;
        }
    } else {
        rep(i, (M+1)/2) {
            ans.emplace_back(low, high);
            low++; high--;
        }
        high--;
        while (sz(ans) < M) {
            ans.emplace_back(low, high);
            low++; high--;
        }
    }
    for (auto p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}