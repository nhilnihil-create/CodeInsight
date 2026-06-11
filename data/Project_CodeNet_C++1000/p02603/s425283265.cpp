#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
  int N,i;
  ll M=1000,S=0;
  cin>>N;
  vector<int> A(N+2);
  A[0]=201;
  A[N+1]=99;
  for (i=1;i<=N;i++) cin>>A[i];
  for (i=1;i<=N;i++) {
    if (A[i-1]>A[i] && A[i]<=A[i+1]) {
      S+=M/A[i];
      M%=A[i];
    } else if (A[i-1]<=A[i] && A[i]>A[i+1]) {
      M+=S*A[i];
      S=0;
    }
  }
  cout<<M<<endl;
  return 0;
}
