#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    int n; cin >> n;
    if (n == 2) {
        int x, y;
        cin >> x >> y;
        int mx = max(x,y);
        int mn = min(x,y);
        cout << mx - mn << endl;
        cout << mx << " " << mn << endl;
        return 0;
    }
    vint pos, neg;
    vector<P> ans;
    rep(i,n) {
        int x; cin >> x;
        if (x >= 0) pos.push_back(x);
        else neg.push_back(x);
    }
    if (neg.empty()) {
        sort(all(pos));
        ans.push_back(P(pos[0],pos[1]));
        neg.push_back(pos[0]-pos[1]);
        pos.erase(pos.begin(),pos.begin()+2);
    }
    if (pos.empty()) {
        sort(rall(neg));
        ans.push_back(P(neg[0],neg[1]));
        pos.push_back(neg[0]-neg[1]);
        neg.erase(neg.begin(),neg.begin()+2);
    }
    while (pos.size() > 1) {
        ans.push_back(P(neg.back(),pos.back()));
        neg.back() -= pos.back();
        pos.pop_back();
    }
    while (neg.size() > 1) {
        ans.push_back(P(pos.back(),neg.back()));
        pos.back() -= neg.back();
        neg.pop_back();
    }
    ans.push_back(P(pos[0],neg[0]));
    cout << pos[0] - neg[0] << endl;
    rep(i,ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}