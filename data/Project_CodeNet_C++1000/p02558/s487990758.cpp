#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
  int N,Q;
  cin>>N>>Q;
  dsu D(N);
  while(Q--){
    int a,b,c;
    cin>>a>>b>>c;
    if(a)cout<<D.same(b,c)<<endl;
    else D.merge(b,c);
  }
}