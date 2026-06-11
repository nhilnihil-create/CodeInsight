#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }
  return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }
  return 0; }
ll MOD = 1000000007;

ll gcd(ll a, ll b){
  if(a > b){
    ll k = a;
    a = b;
    b = k;
  }
  if(a == 0) return b;
  return gcd(b%a,a);
}

int main(){
  ll a,b,c,d; cin >> a >> b >> c >> d;
  ll can;
  ll dan;
  ll e = c*d/gcd(c,d);
  ll ean;
  if(a%c == 0) can = (ll)b/c -(ll)a/c + 1;
  else can = (ll)b/c -(ll)a/c;
  if(a%d == 0) dan = (ll)b/d -(ll)a/d + 1;
  else dan = (ll)b/d -(ll)a/d;
  if(a%e == 0) ean = (ll)b/e -(ll)a/e + 1;
  else ean = (ll)b/e -(ll)a/e;
  cout << (b-a+1) -(can+dan-ean) << endl;
  return 0;
}
