#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define per(i,n) for(int i = (n)-1; i >= 0; --i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

const int INF = 1e9;

int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;
    reverse(all(S));
    vl pos_zero(1,0);
    rep(i,N) {
        if (S[i+1] == '0') {
            pos_zero.push_back(i+1);
        }
    }
    int pre = 0, isOk = 1;
    vl ans;
    while (pre < N) {
        int now = *(upper_bound(all(pos_zero), pre+M) - 1);
        if (now - pre == 0) {
            isOk = 0;
            break;
        }
        ans.push_back(now - pre);
        pre = now;
    }
    reverse(all(ans));
    if (isOk) {
        int n = ans.size();
        rep(i,n) {
            cout << ans[i] << " \n"[i==n-1];
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}
