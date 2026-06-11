#include <bits/stdc++.h>
using namespace std;

int N,M,Q;
int maxans=0;
  int A[51];
  int B[51];
  int C[51];
  int D[51];

void dfs(vector<int>X){
  if(X.size()==N+1){
    int temp=0;
    for(int k=0;k<Q;k++){
      if(X[B[k]]-X[A[k]]==C[k]) temp+=D[k];
    }
    maxans=max(maxans,temp);
  return;
  }
  X.push_back(X.back());
  while(X.back()<=M){
    dfs(X);
    X.back()++;
  }
}


int main(){

  cin>>N>>M>>Q;

  for(int i=0;i<Q;i++){
    cin>>A[i]>>B[i]>>C[i]>>D[i];
  }
  dfs(vector<int>(1,1));
  cout<<maxans<<endl;
    
  return 0;
}
