#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

ull modpow(ll n,ll r){
  ll res = 1;
  while(r){
    if(r & 1)res = res*n%MOD;
    n = n*n %MOD;
    r >>= 1;
  }
  return res;
}

int main(){
  
  string s;
  cin >> s;
  ull res = 0,cnt = 0;
  int n = s.size();
  rep(i,n){
    if(s[i] == '1'){
      (res += modpow(3,n-i-1)*modpow(2,cnt))%=MOD;
      cnt++;
    }
  }
  (res += modpow(2,cnt))%=MOD;
  cout << res << endl;


  return 0;
}