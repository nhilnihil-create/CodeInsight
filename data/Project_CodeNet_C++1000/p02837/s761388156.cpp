#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<vector<int>> h(N);
  vector<vector<int>> u(N);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    for(int j=0;j<a;j++){
      int b,c;
      cin>>b>>c;
      b--;
      if(c==1){
        h[i].push_back(b);
      }
      else{
        u[i].push_back(b);
      }
    }
  }
  int Z=0;
  for(int i=0;i<(1<<N);i++){
    int A=0;
    vector<int> q(N);
    for(int j=0;j<N;j++){
      if(i&(1<<j)){
        q[j]++;
        A++;
      }
    }
    for(int j=0;j<N;j++){
      if(q[j]==1){
        for(int x:h[j]){
          if(q[x]==0){
            A=0;
            break;
          }
        }
        for(int x:u[j]){
          if(q[x]==1){
            A=0;
            break;
          }
        }
      }
    }
    Z=max(A,Z);
  }
  cout<<Z<<endl;

}

