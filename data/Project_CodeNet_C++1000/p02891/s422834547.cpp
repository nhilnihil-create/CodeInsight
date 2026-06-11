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
  string s;
  cin >> s;
  ll k;
  cin >> k;
  bool z = true;
  rep(i, sz(s) - 1){
    if(s[i]!=s[i+1]){
      z = false;
    }
  }
  if(z){
    print(k * sz(s) / 2);
    return 0;
  }
  string ss = s + s;
  string sss = s + s + s;
  string ssss = s + s + s + s;
  string sssss = s + s + s + s + s;
  ll n = 0, m = 0, o = 0, u = 0, a = 0;
  for (ll i = 1; i < sz(s); i++){
    if(s[i]==s[i-1]){
      s[i] = '*';
      n++;
    }
  }
  for (ll i = 1; i < sz(ss);i++){
    if(ss[i]==ss[i-1]){
      ss[i] = '*';
      m++;
    }
  }
  for (ll i = 1; i < sz(sss);i++){
    if(sss[i]==sss[i-1]){
      sss[i] = '*';
      o++;
    }
  }
  for (ll i = 1; i < sz(ssss);i++){
    if(ssss[i]==ssss[i-1]){
      ssss[i] = '*';
      u++;
    }
  }
  for (ll i = 1; i < sz(sssss);i++){
    if(sssss[i]==sssss[i-1]){
      sssss[i] = '*';
      a++;
    }
  }
  ll l = m - n;
  ll p = o - m;
  ll q = u - o;
  ll b = a - u;
  ll ans;
  if(k==1){
    ans = n;
  }
  else if(k==2){
    ans = m;
  }
  else if(k==3){
    ans = o;
  }
  else if(k==4){
    ans = a;
  }
  else{
    ans = a + b * (k - 5);
  }
  print(ans);
}