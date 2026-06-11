#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll N;
  cin>>N;
  vector<ll> vec(N+1);
  for(ll i=0;i<=N;i++){
    cin>>vec.at(i);
  }
  if(N==0){
    if(vec.at(0)==1){cout<<1<<endl;}
    else{cout<<-1<<endl;}
  }
  else if(N>0){
    ll answer=1;
    ll dp[100020];
    dp[0]=1;
    vector<ll> sum(N+1);
    sum.at(N)=vec.at(N);
    for(ll i=N-1;i>=0;i--){
      sum.at(i)=sum.at(i+1)+vec.at(i);
    }
    for(ll i=1;i<=N;i++){
      dp[i]=min(2*(dp[i-1]-vec.at(i-1)),sum.at(i));
      if(dp[i]<=0){cout<<-1<<endl;return 0;}
      //cout<<i<<" "<<dp[i]<<endl;
      answer+=dp[i];
    }
    if(dp[N]!=vec.at(N)){cout<<-1<<endl;return 0;}
    cout<<answer<<endl;
  }
}