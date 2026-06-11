#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;



int main() {
  ll n,x,y;
  cin >> n >> x >> y;
  ll k[n]={};
  for(ll i=1;i<n;i++){
    for(ll j=i+1;j<=n;j++){
      if(i==j)continue;
      ll now=min(abs(i-j),abs(x-i)+1+abs(y-j));
      k[now]++;
    }
  }
  for(int i=1;i<n;i++){cout << k[i] << endl;}
}