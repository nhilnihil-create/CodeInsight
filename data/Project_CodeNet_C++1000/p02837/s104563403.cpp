#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  ll n;
  cin >> n;
  vl a(n);
  vll x(20, vl(20));
  vll y(20, vl(20));
  rep(i,n){
    cin >> a[i];
    rep(j,a[i]){
      cin >> x[i][j] >> y[i][j];
    }
  }
  ll max = 0;
  for (int tmp = 0; tmp < (1 << n); tmp++){
    bitset<15> s(tmp);
    bool OK = true;
    ll count = 0;
    rep(i,n){
      if (s[i]){
        rep(j,a[i]){
          if(y[i][j]!=s[x[i][j]-1]){
            OK = false;
          }
        }
        count++;
      }
    }
    if(OK){
      chmax(max, count);
    }
  }
  print(max);
}