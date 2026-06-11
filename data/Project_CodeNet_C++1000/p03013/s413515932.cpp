#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
ll MOD = 1000000007;

ll sub(ll n){
  if(n<=0){
    return -1;
  }
  else{
    vector<ll> list(n+1);
    rep(i,n+1){
      if(i==0){
        list.at(i) = 0;
      }
      else if(i==1){
        list.at(i) = 1;
      }
      else{
        list.at(i) = (list.at(i-1)+list.at(i-2))%MOD;
      }
    }
  return list.at(n);
  }
}

ll ans(vector<ll> v,ll m){
  ll ans=1;
  for(ll i = 0;i<m;i++){
    if(i==0){
      ans *= sub(v.at(i));
      ans %= MOD;
    }
    else{
      ans *= sub(v.at(i)-v.at(i-1)-1);
      ans %= MOD;
   
    }
    if(ans < 0){
      ans = 0;
    }
  }
  return ans;
}

int main(){  
  ll N,M;
  cin >> N >> M;
  vector<ll> A(M);
  rep(i,M){
    cin >> A.at(i);
  }
  ll ANS = ans(A,M);
  if(M!=0){
    ANS *= sub(N-A.at(M-1));
  }
  else{
    ANS*=sub(N+1);
  }
  cout << ANS%1000000007 << endl;
}