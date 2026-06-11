#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
    int h, w, m;
    cin >> h >> w >> m;
    V<int> cnt_h(h), cnt_w(w);
    set<P> points;
    rep(i,m) {
        int y, x;
        cin >> y >> x;
        y--; x--;
        cnt_h[y]++;
        cnt_w[x]++;
        points.emplace(y,x);
    }
    int mx_h = 0, mx_w = 0;
    rep(i,h) chmax(mx_h, cnt_h[i]);
    rep(i,w) chmax(mx_w, cnt_w[i]);

    V<int> hs, ws;
    rep(i,h) if(cnt_h[i] == mx_h) hs.push_back(i);
    rep(i,w) if(cnt_w[i] == mx_w) ws.push_back(i);
    int ans = mx_w + mx_h;

    for(int i : hs) for(int j : ws) {
        if(points.count(make_pair(i,j))) continue;
        cout << ans << endl;
        return 0;
    }
    ans--;
    cout << ans << endl;
}