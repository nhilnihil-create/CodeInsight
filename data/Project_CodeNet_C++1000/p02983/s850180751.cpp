#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=2019;
int main(){
  ll L,R;
  cin>>L>>R;
  //priority_queue<ll,vector<ll>,greater<ll>>que;
  vector<int>que;
  if(R-L>=2019){
    R=L+2019;
  }
  for(ll i=L;i<=R;i++){
    que.push_back(i%MOD);
    //cout<<i%MOD<<endl;
  }
  int mini=2018;
  for(int i=0;i<que.size()-1;i++){
    for(int j=i+1;j<que.size();j++){
      int tmp=(que[i]*que[j])%MOD;
      mini=min(mini,tmp);
      //cout<<mini<<endl;
    }
  }
  cout<<mini<<endl;
}
