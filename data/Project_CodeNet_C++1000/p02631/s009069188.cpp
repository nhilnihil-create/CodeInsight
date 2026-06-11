#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N,i,X=0;
  cin>>N;
  vector<int> A(N);
  for (i=0;i<N;i++) {
    cin>>A[i];
    X ^= A[i];
  }
  cout<<(X^A[0]);
  for (i=1;i<N;i++) {
  cout<<" "<<(X^A[i]);
  }
  cout<<endl;
  return 0;
}
