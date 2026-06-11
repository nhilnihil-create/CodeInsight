#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int H, W, m;
    cin >> H >> W >> m;

    vector<int> a(H), b(W);
    set<pair<int, int>> bomb;
    rep(i, m){
        int h, w;
        cin >> h >> w;
        h--; w--;
        bomb.insert({h, w});
        a[h]++;
        b[w]++;
    }

    int res1 = 0, res2 = 0;
    int ans = 0;
    rep(i, H)
        res1 = max(res1, a[i]);
    rep(i, W)
        res2 = max(res2, b[i]);
    vector<int> p, q;
    rep(i, H)
        if (a[i] == res1) p.pb(i);
    rep(i, W)
        if (b[i] == res2) q.pb(i);
    if (p.size() * q.size() > m){
        cout << res1 + res2 << endl;
        return 0;
    }
    rep(i, p.size()){
        rep(j, q.size()){
            if (bomb.count({p[i], q[j]}))
                ans = max(ans, res1 + res2 - 1);
            else ans = max(ans, res1 + res2);
        }
    }
    cout << ans << endl;
}