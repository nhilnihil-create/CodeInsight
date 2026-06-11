#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
 
int main(){
  ll N,M,i,t=0;
  string S;
  cin >> N >> M >>S;
  vector<ll> ans(N);
  i=N;
  while(i>0){
    if(i-M<=0){
      ans.at(t)=i;
      t++;
      break;
    }
    ll x=M;
    while(S.at(i-x)=='1'){
      x--;
      if(x==0){
        cout << -1 << endl;
        return 0;
      }
    }
    ans.at(t)=x;
    i-=x;
    t++;
  }
  rep(j,t){
    cout << ans.at(t-j-1) << " ";
  }
  cout << endl;
}
