#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M; cin>>N>>M;
  vector<int>s(M);
  vector<int>c(M);
  vector<vector<bool>>A(N,vector<bool>(10,false));
  for(int i=0;i<M;i++){
    cin>>s[i]>>c[i];
    A[s[i]-1][c[i]]=true;
  }
  if(N==1){
    int B=0;
    for(int i=0;i<10;i++)if(A[0][i]==true)B++;
    if(B>1){cout<<-1<<endl;return 0;}
  }
  else{
    for(int i=0;i<N;i++){
      if(i==0){
        if(A[0][0]==true){cout<<-1<<endl;return 0;}
        int B=0;
        for(int j=1;j<10;j++)if(A[i][j]==true)B++;
        if(B>1){cout<<-1<<endl;return 0;}
      }
      else{
        int B=0;
        for(int j=0;j<10;j++)if(A[i][j]==true)B++;
        if(B>1){cout<<-1<<endl;return 0;}
      }
    }
  }
  int answer=0;
  for(int i=0;i<N;i++)for(int j=0;j<10;j++){int d=pow(10,N-i-1);if(A[i][j]==true)answer+=j*d;}
  if(N==1){cout<<answer<<endl;return 0;}
  cout<<(answer<pow(10,N-1)? answer+pow(10,N-1):answer)<<endl;
}