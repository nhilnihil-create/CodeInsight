#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  ll ans=1;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
    if(A[i]==0){
      cout << 0 << endl;
      return 0;
    }
  }
  for(int i=0;i<N;i++){
    if(ans>(double)1e18/(double)A[i]){
      cout << -1 << endl;
      return 0;      
    }
    if(ans*A[i]>(ll)1e18){
      cout << -1 << endl;
      return 0;          
    }
    ans*=A[i];
  }
  cout << ans << endl;
}