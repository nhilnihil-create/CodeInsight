#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int main()
{
    const ll m = 1e9+7;
    int n,k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    rep(i,n-1) {
        int a,b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    vector<bool> seen(n, false);
    queue<pair<int,int>> que;
    que.push({0,0});
    ll ans = k;

    while(!que.empty()) {
        int cv = que.front().first;
        int cd = que.front().second;
        que.pop();

        seen[cv] = true;
        int nv_cnt = 0;
        for(auto nv:g[cv]) {
            if(seen[nv]) continue;
            que.push({nv,cd+1});
            ++nv_cnt;
        }

        int kc = k - min(2, cd+1);
        rep(i,nv_cnt) {
            ans = (ans*kc) % m;
            kc = max(0, kc-1);
        }
    }

    cout << ans << endl;
    return 0;
}