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
const int inf = 1e9;
const ll inf_l = 1LL<<62;
const int MAX = 1e5;

int main() {
    int n, m; cin >> n >> m;
    vvint data(m);
    rep(i,n) {
        int a, b; cin >> a >> b;
        if (a > m) continue;
        a--;
        data[a].push_back(b);
    }
    priority_queue<int> q;
    int ans = 0;
    rep(i,m) {
        rep(j,data[i].size()) {
            q.push(data[i][j]);
        }
        if (!q.empty()) {
            ans += q.top(); 
            q.pop();
        }
    }
    cout << ans << endl;
}