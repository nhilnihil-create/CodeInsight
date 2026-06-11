#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N,i,j;
  cin>>N;
  vector<int> A(N), C(1e6+1,0);
  vector<bool> B(1e6+1, true);
  for (i=0;i<N;i++) cin>>A[i];
  sort(A.begin(), A.end());
  for (i=0;i<N;i++) {
    C[A[i]]++;
    if (B[A[i]] && C[A[i]]<=1) {
      for (j=2;A[i]*j<1e6+1;j++) {
        B[A[i]*j]=false;
      }
    }
  }
  int ans=0;
  for (i=0;i<N;i++) {
    if (C[A[i]]==1 && B[A[i]]) ans++;
  }
  cout<<ans<<endl;
  return 0;
}
