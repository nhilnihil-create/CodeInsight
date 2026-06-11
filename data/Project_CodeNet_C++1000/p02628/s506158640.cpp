#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int N, K;

int main() {
    cin >> N >> K;
    vector<int> p(N);
    rep(i,N) cin >> p[i];
    sort(p.begin(), p.end());
    int res = 0;
    rep(i,K) res += p[i];
    cout << res << endl;
    return 0;
}