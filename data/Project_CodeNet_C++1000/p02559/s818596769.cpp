#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
  int N,Q;
  cin>>N>>Q;
  fenwick_tree<long long> F(N);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    F.add(i,a);
  }
  while(Q--){
    int a,b,c;
    cin>>a>>b>>c;
    if(a)cout<<F.sum(b,c)<<endl;
    else F.add(b,c);
  }
}