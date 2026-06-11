#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template <class T> inline bool chmax(T &a, T b) {if(a < b) {a= b;return 1;}return 0;}
template <class T> inline bool chmin(T &a, T b) {if(a > b) {a= b;return 1;}return 0;}
ll mod= 1e9 + 7;

ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
    return N * RepeatSquaring(N, P-1, M)%M;
}

ll ncr(ll n,ll a){
  ll ax=1, ay=1;
  for(ll i=n;i>=n-a+1;i--){
    ax=(ax*i)%mod;
  }
  for(ll i=a;i>1;i--){
    ay=(ay*i)%mod;
  }
  ay=RepeatSquaring(ay,mod-2,mod); // フェルマーの小定理
  return (ax*ay)%mod;
}

int main() {
  ll x,y;
  cin >> x >> y;
  ll q=x+y+3;    
  ll p=(x+y)/3;
  ll up=x-p,left=y-p;
  if(q%3!=0 || up<0 || left<0){cout << 0 << endl; return 0;}


  cout << ncr(p,up) << endl;
}