#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M,X;
  cin >> N >> M >> X;
  vector<int> C(N);
  vector<vector<int>> A(N,vector<int> (M));
  for(int i=0;i<N;i++){
    cin >> C.at(i);
    for(int j=0;j<M;j++){
      cin >> A.at(i).at(j);
    }
  }
  int mincost=100000000;
  for(int bit=0;bit<(1<<N);bit++){
    vector<int> rikai(M);
    int cost=0;
    for(int i=0;i<N;i++){
      if(bit &(1<<i)){
        cost+=C.at(i);
        for(int j=0;j<M;j++){
          rikai.at(j)+=A.at(i).at(j);
        }
      }
    }
    bool a=true;
    for(int i=0;i<M;i++){
      if(rikai.at(i)<X){
        a=false;
      }
    }
    if(a){
      mincost=min(mincost,cost);
    }
  }
  if(mincost==100000000){
    cout << -1 << endl;
  }
  else{
    cout << mincost << endl;
  }
}