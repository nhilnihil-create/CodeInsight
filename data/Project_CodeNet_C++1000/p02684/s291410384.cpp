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


struct Doubling { // ダブリング
  vector<vector<int>> to; // to[i][j] = jから2^i回操作した値
  int mx;
  Doubling(int n, int d, const vector<int> &a):to(d, vector<int>(n)) {
    mx = d;
    to[0] = a;
    for(int i = 1; i < mx; i++) for(int j = 0; j < n; j++) {
      to[i][j] = to[i-1][to[i-1][j]];
    }
  }
  int operator()(int s, long long k) { // sからk回操作後の値を返す
    int res = s;
    for(int i = mx-1; i >= 0; i--) {
      long long l = 1LL<<i;
      if(l <= k) {
        res = to[i][res];
        k -= l;
      }
    }
    return res;
  }
};

const int MX = 60;

int main(){
    
    int n;
    ll k;
    cin >> n >> k;
    V<int> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i]--;
    }
    Doubling d(n,MX,a);
    int ans = d(0,k)+1;
    cout << ans << endl;
}