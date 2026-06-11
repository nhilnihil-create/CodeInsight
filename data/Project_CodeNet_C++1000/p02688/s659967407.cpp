#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N,K,i,j;
  cin>>N>>K;
  vector<bool> B(N,true);
  for (i=0;i<K;i++) {
    int d,a;
    cin>>d;
    for (j=0;j<d;j++) {
      cin>>a;
      B[a-1]=false;
    }
  }
  int ans=0;
  for (i=0;i<N;i++) {
    if (B[i]) ans++;
  }
  cout<<ans<<endl;
  return 0;
}
