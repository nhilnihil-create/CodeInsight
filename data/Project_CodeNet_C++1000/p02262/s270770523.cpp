#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin>>n;
  int A[n];
  for (int i=0; i<n; i++) {
    cin>>A[i];
  }
  int cnt=0;
  vector<int> G;
  for (int h=1; ; ) {
    if (h>n) {
      break;
    }
    G.push_back(h);
    h=3*h+1;
  }
  for (int i=G.size()-1; i>=0; i--) {
    for (int j=G[i]; j<n; j++) {
      int v=A[j];
      int k=j-G[i];
      while (k>=0 && A[k]>v) {
        A[k+G[i]]=A[k];
        k-=G[i];
        cnt++;
      }
      A[k+G[i]]=v;
    }
  }
  cout<<G.size()<<endl;
  for (int i=G.size()-1; i>=0; i--) {
    cout<<G[i]<<(i==0?"":" ")<<flush;
  }
  cout<<endl;
  cout<<cnt<<endl;
  for (int i=0; i<n; i++) {
    cout<<A[i]<<endl;
  }
  return 0;
}

