#include<bits/stdc++.h>
using namespace std;
int N,K;
vector<int>d;
vector<vector<int>>A;
void first(){
  cin >> N >> K;
  d.resize(K);
  A.resize(K,vector<int>());
  for(int i=0;i<K;i++){
    cin >> d[i];
    A[i].resize(d[i]);
    for(int j=0;j<d[i];j++){
      cin >> A[i][j];
    }
  }
}
  
  void second(){
    int ans=0;
    for(int i=1;i<=N;i++){
      bool have=false;
      for(auto x:A){
        for(auto y:x){
          if(i==y)have=true;
        }
      }
      if(!have)ans++;
    }
    cout << ans << endl;
  }

int main(){
  first();
  second();
}