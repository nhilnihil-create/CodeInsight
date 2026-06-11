#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N,i;
  string S;
  cin>>N>>S;
  vector<int> W(N+1,0),R(N+1,0);
  for (i=0;i<N;i++) {
    if (S[i]=='W') {
      W[i+1]=W[i]+1;
      R[i+1]=R[i];
    } else {
      W[i+1]=W[i];
      R[i+1]=R[i]+1;
    }
  }
  cout<<W[R[N]]<<endl;
  return 0;
}
