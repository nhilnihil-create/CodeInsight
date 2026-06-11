#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;cin>>N;
  vector<ll> A(N+1);
  for(int i=1;i<=N;i++) cin>>A[i];
  
  sort(A.begin(),A.end());
  for(int i=1;i<=N-1;i++){
    if(A[i]==A[i+1]){
      cout << "NO" << endl;
      return 0;
    }
  }
  
  cout << "YES" << endl;
}
