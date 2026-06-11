#include<iostream>
#include<vector>
using namespace std;
int main() {
  int N,M,K,i,j;
  cin>>N>>M>>K;
  vector<int> A(N+1), B(M+1);
  for (i=0;i<N;i++) cin>>A[i];
  for (j=0;j<M;j++) cin>>B[j];
  int k=K;
  for (i=0;i<N && A[i]<=k;i++) {
    k-=A[i];
  }
  for (j=0;j<M && B[j]<=k;j++) {
    k-=B[j];
  }
  int I=i, ANS=i+j, ans=i+j;
  for (i=I-1;i>=0;i--) {
    ans--;
    k+=A[i];
    for (;j<M && B[j]<=k;j++) {
      ans++;
      k-=B[j];
    }
    ANS = max(ANS, ans);
  }
  cout << ANS <<endl;
  return 0;
}
