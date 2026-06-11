#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);

int N, M, Q;
vi a, b, c, d;

int dfs(int i, vi &A) {
    if (i == N) {
        int ans = 0;
        rep(j, Q) {
            if (A.at(b.at(j) - 1) - A.at(a.at(j) - 1) == c.at(j)) ans += d.at(j);
        }
        return ans;
    }
    int ret = 0;
    rep2(j, 1, M + 1) {
        if (i == 0) {
            A.push_back(j);
            ret = max(dfs(i + 1, A), ret);
            A.pop_back();
        } else {
            if (A.at(A.size() - 1) <= j) {
                A.push_back(j);
                ret = max(dfs(i + 1, A), ret);
                A.pop_back();
            }
        }
    }
    return ret;
}

int main() {
    cin >> N >> M >> Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    rep(i, Q) { cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i); }
    vi A;
    cout << dfs(0, A) << endl;
}
