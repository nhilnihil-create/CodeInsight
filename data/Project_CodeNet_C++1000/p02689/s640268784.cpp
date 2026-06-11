#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i ++)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;// = 998244353;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

int main() {
    int N,M; cin >> N >> M;
    vector<int> H(N);
    rep(i,N) cin >> H[i];
    vector<vector<int>> G(N);
    rep(i,M) {
        int a,b; cin >> a >> b;
        --a; -- b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 0;
    rep(i,N) {
        bool flag = true;
        for (int j:G[i]) {
            if (H[j] >= H[i]) {
                flag = false;
                break;
            }
        }
        if (flag) ++ans;
    }
    cout << ans << '\n';
    return 0;
}