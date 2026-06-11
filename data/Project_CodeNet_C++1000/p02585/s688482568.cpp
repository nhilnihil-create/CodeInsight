#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const ll INF = 1e18 + 10;

int N, K;

int main() {
    cin >> N >> K;
    vector<int> P(N);
    vector<ll> C(N);
    rep(i,N) cin >> P[i], P[i]--;
    rep(i,N) cin >> C[i];

    ll res = -INF;

    rep(i,N) {
        int v = i;
        int cycle_sz = 0;
        ll cycle_sum = 0;
        while (true)
        {
            cycle_sz++;
            cycle_sum += C[v];
            v = P[v];
            if (v == i) break;
        }

        int cnt = 0;
        ll path = 0;
        while(true) {
            cnt++;
            path += C[v];

            if(cnt > K) break;

            int num = (K - cnt) /cycle_sz;
            ll score = path + max(0LL, cycle_sum) * num;
            chmax(res, score);

            v = P[v];
            if (v == i) break;
        }
    }
    cout << res << endl;
}
