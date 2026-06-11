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
const int inf = 1<<30;
const ll inf_l = 1LL<<61;
const int MAX = 1e5;

int main() {
    int n; cin >> n;
    vector<P> data(n);
    rep(i,n) {
        int a, b; cin >> a >> b;
        data[i] = P(a,b);
    }
    for (int i = 0; i <= n-3; i++) {
        bool ok = true;
        rep(j,3) if (data[i+j].first != data[i+j].second) ok = false;
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}