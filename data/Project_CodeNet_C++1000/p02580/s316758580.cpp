#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int H, W, M; cin >> H >> W >> M;
    vector<int> h(H), w(W);
    set<P> bombs;
    rep(i,M){
        int a, b; cin >> a >> b;
        a--, b--;
        bombs.insert(P(a,b));
        h[a]++;
        w[b]++;
    }
    int mx_h = 0, mx_w = 0;
    vector<int> hs, ws;
    rep(i, H) if(mx_h < h[i]) mx_h = h[i];
    rep(i, W) if(mx_w < w[i]) mx_w = w[i];
    rep(i, H) if(h[i] == mx_h) hs.push_back(i);
    rep(i, W) if(w[i] == mx_w) ws.push_back(i);
    int ans = mx_h + mx_w;
    rep(i, hs.size()){
        rep(j, ws.size()){
            if(bombs.count(P(hs[i], ws[j]))) continue;
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans - 1 << endl;
    return 0;
}