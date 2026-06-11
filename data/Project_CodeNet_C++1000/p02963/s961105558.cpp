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
    ll s; cin >> s;
    int x1 = 0, y1 = 0;
    int x2, y2, x3, y3;
    if (s > 1e9) {
        y3 = 1e9;
        x2 = (s+y3-1)/y3;
        x3 = (ll)x2*y3 - s;
        y2 = 1;
    } else {
        y3 = s;
        x2 = 1;
        y2 = 0;
        x3 = 0;
    }
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " ";
    cout << x3 << " " << y3 << endl;
}