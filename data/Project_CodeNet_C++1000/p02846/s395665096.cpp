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
    int t1, t2; cin >> t1 >> t2;
    ll a1, a2, b1, b2; 
    cin >> a1 >> a2 >> b1 >> b2;
    ll v1 = a1 - b1, v2 = a2 - b2;
    ll dis = v1*t1 + v2*t2;
    if ((v1 > 0 && dis > 0) || (v1 < 0 && dis < 0)) cout << 0 << endl;
    else if (v1*dis == 0) cout << "infinity" << endl;
    else {
        ll ans;
        dis = abs(dis);
        v1 = abs(v1);
        if ((v1*t1) % dis == 0) ans = (v1*t1/dis+1)*2 - 2;
        else ans = (v1*t1/dis+1)*2 - 1;
        cout << ans << endl;
    }
}