#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1<<30;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
int main(){
  int n;  cin >> n;
  vector<ll> a(n), b(n);
  rep(i,0,n){
    cin >> a[i] >> b[i];
  }
  ll mi = INF;
  if(n==1){
    cout << 1 << endl;
    return 0;
  }
  rep(i,0,n)rep(j,0,n){
    if(i==j) continue;
    ll dx = a[i]-a[j], dy = b[i] - b[j];
    ll res = 0;
    rep(i2,0,n)rep(j2,0,n){
      if(i2==j2) continue;
      if(dx==a[i2]-a[j2] && dy==b[i2]-b[j2]) res++;
    }
    chmin(mi, n-res);
  }
  cout << mi << endl;
  return 0;
}
