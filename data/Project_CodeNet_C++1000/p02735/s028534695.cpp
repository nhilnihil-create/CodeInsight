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

vint dx = {1,0};
vint dy = {0,1};

int h, w;
vector<string> field;
vvint ct;

void dfs(int x, int y) {
    rep(i,2) {
        int n_x = x + dx[i];
        int n_y = y + dy[i];
        if ((n_x >= 1 && n_x <= w &&  n_y <= h) || (x == w && y == h)) {
            if (field[y][x] != field[n_y][n_x]) {
                if (chmin(ct[n_y][n_x],ct[y][x]+1)) dfs(n_x,n_y);
            } else {
                if (chmin(ct[n_y][n_x],ct[y][x])) dfs(n_x,n_y);
            }
        }
    }
}

int main() {
    cin >> h >> w;
    field.assign(h+2,string(w+2,'.'));
    ct.assign(h+2,vint(w+2,inf));
    ct[1][0] = 0;
    REP(i,h+1) {
        string s; cin >> s;
        REP(j,w+1) field[i][j] = s[j-1];
    }
    dfs(0,1);
    int ans = ct[h+1][w] / 2;
    cout << ans << endl;
}