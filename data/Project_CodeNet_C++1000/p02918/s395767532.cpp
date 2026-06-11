#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N>>K;
  string S;
  cin>>S;
  int cnt=0;
  for(int i=0;i<N-1;i++){
    if(S.at(i)=='R' && S.at(i+1)=='L') cnt++;
  }
  int cntb=0;
  
  if(S.at(0)=='L') cntb++;
  if(S.at(N-1)=='R') cntb++;
  
  //cout<<cnt<<" "<<cntb<<endl;
  
  if(cnt<=K){
    int temp=cnt;
    cnt=0;
    K-=temp;
  }
  
  else{
    cnt-=K;
    K=0;
  }
  //cout<<cnt<<" "<<cntb<<" "<<K<<endl;
  if(cntb<=K){
    cntb=0;
  }
  else{
    cntb-=K;
  }
  //cout<<cnt<<" "<<cntb<<endl;
  int ans=N;
  if(cnt != 0){
    ans=ans-cnt*2-cntb;
  }
  else{
    if(cntb == 2){
      ans=ans-2;
    }
    else{
      ans=ans-1;
    }
  }
  
  cout<<ans<<endl;
  return 0;
}
