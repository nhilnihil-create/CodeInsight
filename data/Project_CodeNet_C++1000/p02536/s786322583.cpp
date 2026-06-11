#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int N,M;cin>>N>>M;
  dsu d(N);
  for(int i=0;i<M;i++){
    int A,B;cin>>A>>B;
    d.merge(A-1,B-1);
  }
  vector<bool>a(1001000,false);
  for(int i=0;i<N;i++)a[d.leader(i)]=true;
  int c=0;
  for(int i=0;i<N;i++)if(a[i])c++;
  cout<<c-1<<endl;
}