#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> X(N);
  for(int i=0;i<N;i++){
    cin>>X[i];
  }
  int L=X[0];
  int R=X[0];
  for(int i=0;i<N;i++){
    L=min(L,X[i]);
    R=max(R,X[i]);
  }
  int ans=1000000000;
  for(int i=L;i<=R;i++){
    int P=0;
    for(int j=0;j<N;j++){
      P+=(X[j]-i)*(X[j]-i);
    }
    ans=min(ans,P);
  }
  cout<<ans<<endl;
}
    
    