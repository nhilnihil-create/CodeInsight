#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define per(i,n) for(int i = (n)-1; i >= 0; --i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

struct Testimony {
    int x, y;
};
using vt = vector<Testimony>;
using vvt = vector<vt>;

int main() {
    int N;
    cin >> N;
    vvt ts(N);
    rep(i,N) {
        int A;
        cin >> A;
        rep(j,A) {
            int x, y;
            cin >> x >> y;
            ts[i].push_back(Testimony{x-1, y});
        }
    }
    int ans = 0;
    rep(b,(1<<N)) {
        vl isHonest(N);
        int honest_cnt = 0, isOk = 1;
        rep(i,N) {
            isHonest[i] = (b>>i) & 1;
            honest_cnt += isHonest[i];
        }
        rep(i,N) {
            if (!isHonest[i]) continue;
            rep(j,int(ts[i].size())) {
                if (isHonest[ts[i][j].x] == ts[i][j].y) continue;
                isOk = false;
            }
        }
        if (isOk) {
            ans = max(ans, honest_cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
