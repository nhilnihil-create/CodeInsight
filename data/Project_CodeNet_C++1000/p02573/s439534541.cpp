#include <bits/stdc++.h>
using namespace std; 

int find(int X,vector<int> &P){
  if(P.at(X)<0){
    return X;
  }
  return P.at(X)=find(P.at(X),P);
}

void unite(int X,int Y,vector<int> &P){
  X=find(X,P);
  Y=find(Y,P);
  if(X==Y){
    return;
  }
  P.at(X)+=P.at(Y);
  P.at(Y)=X;
  return;
}
int main(){
  int N,M;
  cin >> N >> M;
  vector<int> P(N,-1);
  for(int i=0;i<M;i++){
    int A,B;
    cin >> A >> B;
    unite(A-1,B-1,P);
  }
  sort(P.begin(),P.end());
  cout << (-1)*P.at(0) << endl;
}
    