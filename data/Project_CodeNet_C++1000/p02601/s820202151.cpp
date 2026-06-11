#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,b) for (ll i=a;i<=ll(b);i++)
using namespace std;
ll ctoi(const char c){if('0'<=c&&c<='9') return (c-'0');return -1;}
#define ALL(x) begin(x),end(x)
  
int main(){
  ll a,b,c,k;
  cin >> a >> b >> c >> k;
  bool flag = false;
  for(ll i=0;i<k;i++){
      if(c<=b){
        c*=2;
        continue;
      }
      if(b<=a){
        b*=2;
        continue;
      }
  }
  if(c>b&&b>a) cout << "Yes" << endl;
  else cout << "No" << endl;
}