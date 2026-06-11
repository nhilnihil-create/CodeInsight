#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> X(N,0);
  vector<pair<int,int>> P;
  for(int i=0;i<N;i++){
    cin>>X[i];
  }
  sort(X.begin(),X.end());
  
  for(int i=1;i<N-1;i++){
    if(X[i]>0){
      P.emplace_back(X[0],X[i]);
      X[0]-=X[i];
    }
    else{
      P.emplace_back(X[N-1],X[i]);
      X[N-1]-=X[i];
    }
  }
  
  /*cout<<X[0]-X[N-1]<<endl;
  
  for(int i=0;i<N-2;i++){
    cout<<setprecision(20)<<P[i].first<<" "<<P[i].second<<endl;
  }*/
  
    P.emplace_back(X[N-1],X[0]);
    cout << X[N-1] - X[0] << endl;
    for(auto &e : P){
        cout << e.first << " " << e.second << endl;
    }
  
  return 0;
}