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
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  ll n;
  cin >> n;
  vl l(n);
  rep(i,n){
    cin >> l[i];
  }
  ll total = 0;
  sort(all(l));
  for (ll i = 0; i < n - 2;i++){
    for (ll j = i + 1; j < n - 1;j++){
      for (ll k = j + 1; k < n;k++){
        if(l[i]+l[j]>l[k]){
          total++;
        }
        else{
          break;
        }
      }
    }
  }
  print(total);
}
