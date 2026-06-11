
#include<bits/stdc++.h>
using namespace std;
int main(){
  long N;cin>>N;
  vector<long>A(N),X(N),Y(N);
  vector<long>C; //id->値
  map<long,long>D;// 値->id
  for(long i=0;i<N;i++){
    cin>>A[i];
    X[i]=i-A[i];
    Y[i]=i+A[i];
    C.push_back(X[i]);
    C.push_back(Y[i]);
  }sort(C.begin(),C.end());
  for(long i=0;i<C.size();i++){
    D[C[i]]=i;
  }
  vector<long>L(C.size(),0);
  for(long i=0;i<N;i++){
    L[D[X[i]]]+=1;
  }
  long ans=0;
  for(long i=0;i<N;i++){
    ans+=L[D[Y[i]]];
  }
  
  cout<<ans;
  
}

