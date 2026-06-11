#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9+7;
const ll inf_l = 1e18;
const int MAX = 1e6;

int main() {
    int n; cin >> n;
    vector<P> data(n);
    rep(i,n) {
        int x, y; cin >> x >> y;
        data[i] = P(x,y);
    }
    map<P,int> mp;
    rep(i,n)rep(j,n) {
        if (i == j) continue;
        int x = data[i].first - data[j].first;
        int y = data[i].second - data[j].second;
        mp[P(x,y)]++;
    }
    int mx = 0;
    for (auto p : mp) chmax(mx,p.second);
    cout << n-mx << endl;
}