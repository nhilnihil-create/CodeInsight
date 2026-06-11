#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

vl divisor(ll n) {
  vl div;
  for(ll i=1;i*i<=n;i++) {
    if(i*i<n&&!(n%i)) {
      div.push_back(i);
      div.push_back(n/i);
    }
    else if(i*i==n) div.push_back(i);
  }
  return div;
}

int main() {
  ll N;
  cin >> N;
  int ans=0;
  vl div=divisor(N);
  for(ll x:div) {
    if(x==1) continue;
    ll num=N;
    while(!(num%x)) num/=x;
    ans+=(num%x==1);
  }
  ans+=divisor(N-1).size();
  cout << --ans << endl;
}