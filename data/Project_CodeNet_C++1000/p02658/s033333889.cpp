#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
ll MOD=1000000007;

int main(){
  int n; cin>>n;
  vector<ll>A(n);
  rep(i,n){
    cin>>A[i];
    if (A[i]==0){
      cout << 0;
      return 0;
    }
  }
  ll ans = A[0];
  for(int i=1; i<n; i++){
    if (A[i]<=(1000000000000000000/ans)){
      ans *= A[i];
    }
    else{
      ans = -1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}