#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin>>N;
    vector<vector<ll>> as(N, vector<ll>(N));
    rep(i, N) {
        rep(j, N - 1) {
            ll a;
            cin>>a; a--;
            as[i][j] = a;
        }
    }

    vector<ll> is(N);
    bool contested = true;
    ll cnt = 0;
    while(contested) {
        contested = false;
        vector<bool> visited(N, false);
        rep(i, N) {
            if (is[i] == N - 1) continue;

            ll a = as[i][is[i]];
            if (visited[i]) continue;
            if (visited[a]) continue;

            if (as[a][is[a]] == i) {
                is[i]++; is[a]++;
                contested = true;
                visited[i] = true;
                visited[a] = true;
            }
        }
        if (contested) cnt++;
    }

    ll ans = cnt;
    rep(i, N) if (is[i] != N - 1) ans = -1;
    cout<<ans<<endl;
}