#include<bits/stdc++.h>
using namespace std;

int find(int X,vector<int>&P){
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
  if(P.at(X)<P.at(Y)){
    swap(X,Y);
  }
  P.at(X)+=P.at(Y);
  P.at(Y)=X;
}

int main(){
  int N,M,count=0;
  cin >> N >> M;
  vector<int> P(N,-1);
  for(int i=0;i<M;i++){
    int A,B;
    cin >> A >> B;
    unite(A-1,B-1,P);
  }
  for(int i=0;i<N;i++){
    if(P.at(i)<0){
      count++;
    }
  }
  cout << count-1 << endl;
}

  