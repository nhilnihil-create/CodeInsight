#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main(){
  ll N,K;
  cin>>N>>K;
  vector<ll> A(N),F(N);
  for(int i(0);i<N;i++) cin>>A[i];
  for(int i(0);i<N;i++) cin>>F[i];
  sort(A.begin(),A.end());
  sort(F.rbegin(),F.rend());
  ll l = -1,r = 1e12;
  while(l+1<r){
    ll x = (l+r)/2;
    bool ok = [&]{
      ll sum(0);
      vector<ll> Ai(N);
      for(int i(0);i<N;i++){
        Ai[i] = x/F[i];
      }
      for(int i(0);i<N;i++){
        sum += max(0ll,A[i] - Ai[i]);
      }
      //cout << x << " " << sum <<" " << K<< endl;
      if(sum <= K) return true;
      else return false;
    }();
    if (ok) r = x;
    else l = x;
  }
  cout << r << endl;

  return 0;
}

