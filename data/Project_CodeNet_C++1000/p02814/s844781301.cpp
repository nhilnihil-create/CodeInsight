#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }

    else {
        return gcd(y, x % y);
    }
}

int lcm(int x, int y) {
    int g = gcd(x, y);
    int l = x * y / g;
    return l;
}

int main() {
  ll N,M;
  cin>>N>>M;
  vector<ll> v(N);
  for(ll i = 0LL; i < N; i++) {
    ll a;
    cin>>a;
    v[i]=a/2LL;
  }
  ll cnt = 0LL;
  ll t = v[0];
  while(t%2LL==0LL){
    t/=2LL;
    cnt++;
  }
  ll G = 1LL;
  bool can = true;
  for(ll i = 0LL; i < N; i++){
    ll cntn = 0LL;
    ll s = v[i];
    while(s%2LL==0LL){
      s/=2LL;
      cntn++;
    }
    if(cntn!=cnt){
      can=false;
      break;
    }
    G=(G/gcd(G,v[i]))*v[i];
    if(G>M) {
      can = false;
      break;
    }
  }
  M=M/G;
  M=(M+1LL)/2LL;
  if(can) cout<<M<<endl;
  else cout<<0<<endl;
}