#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int main()
{
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    rep(i,n) rep(j,n-1) { cin >> a[i][j]; a[i][j]--; }

    vector<int> d(n,0);
    vector<int> p(n,0);
    queue<pair<int,int>> que;

    rep(i,n) {
        if(a[a[i][0]][0] == i)
            que.push({i,p[i]});
    }

    int ans = 0;
    while(!que.empty()) {
        int player = que.front().first;
        int pp = que.front().second;
        que.pop();
        if(p[player] > pp) continue;

        int opponent = a[player][pp];
        int po = p[opponent];
        if(po >= n-1 || a[opponent][po] != player) 
            continue;

        int nd = max(d[player], d[opponent]) + 1;
        d[player] = d[opponent] = nd;
        p[player]++;
        p[opponent]++;

        if(p[player] < n-1) que.push({player,p[player]});
        if(p[opponent] < n-1) que.push({opponent,p[opponent]});

        ans = max(ans, nd);
    }

    rep(i,n) {
        if(p[i] < n-1) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 0;
}