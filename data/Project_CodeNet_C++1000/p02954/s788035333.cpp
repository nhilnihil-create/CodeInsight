#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  int N=S.size();
  int r,A=1;
  vector<int> p(N);
  for(int i=1;i<N;i++){
    if(S[i-1]==S[i]){
      A++;
    }
    else if(S[i-1]=='R'){
      r=i-1;
      p[r]+=(A+1)/2;
      p[r+1]+=A/2;
      A=1;
    }
    else{
      p[r]+=A/2;
      p[r+1]+=(A+1)/2;
      A=1;
    }
  }
  p[r]+=A/2;
  p[r+1]+=(A+1)/2;
  for(int i=0;i<N;i++){
    cout<<p[i];
    if(i!=N-1){
      cout<<" ";
    }
  }
}