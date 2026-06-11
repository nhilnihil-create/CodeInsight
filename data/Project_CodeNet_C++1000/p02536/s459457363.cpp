#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
  int N,M;cin>>N>>M;
  dsu X(N);
  for(int i=0;i<M;i++){
    int A,B;cin>>A>>B;
    X.merge(A-1,B-1);
  }
  cout<<X.groups().size()-1<<endl;
}
