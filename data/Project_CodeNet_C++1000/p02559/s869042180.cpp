#include <atcoder/fenwicktree>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

int main() {
  int N,Q;
  cin>>N>>Q;
  fenwick_tree<long long> fw(N);
  long long a;
  for(int i=0;i<N;i++){
    cin>>a;
    fw.add(i,a);
  } 
  long long t,u,v;
  for(int i=0;i<Q;i++){
    cin>>t>>u>>v;
    if(t==0){
      fw.add(u,v);
    }
    if(t==1){
      long long ans=fw.sum(u,v);
      cout<<ans<<endl;
    }
  }
  return 0;
}

