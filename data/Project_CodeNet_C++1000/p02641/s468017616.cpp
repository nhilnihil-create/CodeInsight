#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int X, N;


int main() {
    cin >> X >> N;
    vector<int> p(N);
    rep(i,N) cin >> p[i];
    auto it = find(p.begin(), p.end(), X);
    if (it == p.end()) {
        cout << X << endl;
        return 0;
    }
    int diff = 1005;
    int res = 1005;
    rep(i,102) {
        it = find(p.begin(), p.end(), i);
        if (it == p.end() && abs(X - i) < diff) {
            diff = abs(X - i);
            res = i;
        }
    }
    cout << res << endl;
}