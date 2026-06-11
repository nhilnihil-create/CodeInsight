#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,M;
  cin>>N>>M;
  priority_queue<ll> que;
  for(ll i=0;i<N;i++){
    ll tmp;
    cin>>tmp;
    que.push(tmp);
  }
  for(ll i=0;i<M;i++){
    ll tmp=que.top();
    que.pop();
    tmp=tmp/2;
    que.push(tmp);
  }

  ll ans=0;
  for(ll i=0;i<N;i++){
    ans+=que.top();
    que.pop();
  }
  cout<<ans<<endl;
}