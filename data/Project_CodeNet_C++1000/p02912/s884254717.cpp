#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define per(i,n) for(int i = (n)-1; i >= 0; --i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main() {
    ll N, M;
    cin >> N >> M;
    priority_queue<ll> que;
    rep(i,N) {
        ll A;
        cin >> A;
        que.push(A);
    }
    rep(i,M) {
        ll A = que.top(); que.pop();
        A >>= 1;
        que.push(A);
    }
    ll ans = 0;
    while (!que.empty()) {
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
    return 0;
}
