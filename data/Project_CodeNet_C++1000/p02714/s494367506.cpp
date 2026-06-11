#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  string S; cin>>S;
  vector<int>R(N,0);
  vector<int>G(N,0);
  vector<int>B(N,0);
  int count=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='R')R[i]=1;
    else if(S.at(i)=='G')G[i]=1;
    else{
      B[i]=1;
      count++;
    }
  }
  long long ans=0;
  for(int i=0;i<N;i++){
    if(R[i]==1){
      for(int j=0;j<N;j++){
        if(G[j]==1){
          ans+=count;
          if(min(i,j)*2-max(i,j)>=0)if(B[min(i,j)*2-max(i,j)]==1)ans--;
          if(max(i,j)*2-min(i,j)<N)if(B[max(i,j)*2-min(i,j)]==1)ans--;
          if((max(i,j)-min(i,j))%2==0&&B[min(i,j)+(max(i,j)-min(i,j))/2]==1)ans--;
        }
      }
    }
  }
  cout<<ans<<endl;
}