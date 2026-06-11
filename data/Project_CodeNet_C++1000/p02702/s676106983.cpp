#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<ll,ll>;
using vi = vector<ll>;
using vv = vector<vi>;

int powmod(int a, int n, int m){
  int rtn = 1;
  while(n){
    if(n&1)
      rtn = rtn * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return rtn;
}

int main(){
  string s;
  cin >> s;
  
  vi c(2019, 0);
  int a = 0;
  c[0] = 1;
  rep(i,(int)s.size()){
    a += powmod(10, (int)s.size()-1-i, 2019)*(s[i] - '0');
    a %= 2019;
    //cout<<i+1<<" "<<a<<endl;
    c[a]++;
  }
  ll ans = 0;
  rep(i,2019){
    ans += c[i]*(c[i]-1)/2;
  }
  cout << ans << endl;
  return 0;
}