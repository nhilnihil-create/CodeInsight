#include<bits/stdc++.h>
using namespace std;

int main(){

  long long N, N_, i, cnt=0;
  map<long long, long long> Ss;
  cin>>N;
  N_=N;
  
  for(i=2; i*i<=N_; i++){
    while(N%i==0){
      Ss[i]++;
      N/=i;
    }
  }
  if(N!=1)Ss[N]++;
  
  for(auto p : Ss){
    long long e=p.second;
    long long tmp=0, cur=1;
    while(e>=cur) e-=cur++, tmp++;
    cnt+=tmp;
  }
  cout<<cnt<<endl;
  return 0;
}