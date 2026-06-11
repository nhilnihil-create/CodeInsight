#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N,M,i;
  cin>>N>>M;
  vector<bool> B(N,true);
  vector<int> H(N);
  for (i=0;i<N;i++) {
    cin>>H[i];
  }
  int a,b;
  for (i=0;i<M;i++) {
    cin>>a>>b;
    if (H[a-1] <= H[b-1]) B[a-1] = false;
    if (H[a-1] >= H[b-1]) B[b-1] = false;
  }
  int ans=0;
  for (i=0;i<N;i++) {
    if (B[i]) ans++;
  }
  cout<<ans<<endl;
  return 0;
}
