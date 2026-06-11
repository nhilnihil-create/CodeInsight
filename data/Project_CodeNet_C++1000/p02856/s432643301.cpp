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

ll ans = 0;

void f(int x, ll n, deque<int> &q) {
    if (n == 0) return;
    if (n&1) q.push_back(x);
    int ct = 0;
    int v = 10 * x + x;
    while (v >= 10) {
        ct++;
        v -= (to_string(v)[0]-'0') * 9;
    }
    if (x == 0) ct++;
    ans += ct * (n/2);
    f(v,n/2,q);
}

int main() {
    int m; cin >> m;
    deque<int> q;
    rep(i,m) {
        int d;
        ll c; 
        cin >> d >> c;
        f(d,c,q);
    }
    while (q.size() != 1) {
        ans++;
        int a = q.front(); q.pop_front();
        int b = q.front(); q.pop_front();
        int sum = a + b;
        q.push_front(sum%10);
        sum /= 10;
        if (sum != 0) q.push_front(sum);
    }
    cout << ans << endl;
}