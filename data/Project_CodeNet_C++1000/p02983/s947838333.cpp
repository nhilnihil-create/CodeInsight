#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int L, R;
int rem[2025];

int main() {
    cin >> L >> R;
    for (int i = L; i <= min(L+2019, R); ++i) {
        rem[i%2019]++;
    }
    int res = INF;
    rep(i, 2019) if (rem[i] > 1) chmin(res, (i*i)%2019);
    rep(i, 2019) rep(j, i) {
        if (rem[i] && rem[j]) {
            chmin(res, (i*j)%2019);
        }
    }
    cout << res << endl;
}
