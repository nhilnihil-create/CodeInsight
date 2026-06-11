#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
  int N,i,j;
  ll K;
  cin>>N>>K;
  vector<int> A(N);
  vector<vector<int> > B(63, vector<int>(N));
  for (i=0;i<N;i++) {
    cin>>A[i];
    B[0][i] = A[i] - 1;
  }
  for (i=1;i<63;i++) {
    for (j=0;j<N;j++) {
      B[i][j] = B[i-1][B[i-1][j]];
    }
  }
  int town=0;
  for (i=0;i<63;i++) {
    if (K>>i & 1) {
      town = B[i][town];
    }
  }
  cout<<town + 1<<endl;
  return 0;
}
