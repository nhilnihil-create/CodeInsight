#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M,X;
  cin >>N>>M>>X;
  
  vector<int> S(M,0);
  vector<vector<int>> A(N,vector<int>(M+1));
  for(int i=0;i<N;i++){
    for(int j=0;j<M+1;j++){
      cin >>A[i][j];
      S[j]+=A[i][j];
    }
  }
  
  int ans=10000000,e=0,cnt=0,d=0;
  for(int i=0;i<1<<N;i++){
    vector<int> S(M,0);
    int an=0;
    d=0;
    for(int j=0;j<N;j++){
      if(i>>j&1){
        an+=A[j][0];
        for(int k=1;k<M+1;k++){
          S[k-1]+=A[j][k];
        }
      }
      if(j==N-1){
        for(int k=1;k<M+1;k++){
            if(S[k-1]>=X){
              if(k==M){
                d=1;
                continue;
              }
             
            }
            else{
              break;
            }
        }
      }
          
      if(j==N-1 && d==1 ){
        ans=min(ans,an);
        e=1;
      }
    }
  }
  if(e){
  cout << ans <<endl;
  }
  else{
    cout << -1 <<endl;
  }
}