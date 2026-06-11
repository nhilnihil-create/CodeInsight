#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll num[200005]={0},goal[200005]={0};
int main(){
  ll n;
  cin>>n;
  priority_queue<P> pque;
  for(int i=0;i<n;i++) cin>>goal[i];
  for(int i=0;i<n;i++) cin>>num[i];
  for(int i=0;i<n;i++){
    ll pas=(i+n-1)%n,nxt=(i+1)%n;
    if(num[pas]+num[nxt]<num[i]&&goal[i]!=num[i]) pque.push(P(num[i],i));
  }
  ll ans=0;
  while(!pque.empty()){
    P p=pque.top();
    pque.pop();
    ll val=p.first,pos=p.second;
    ll pas=(pos+n-1)%n,nxt=(pos+1)%n;
    ll wk=num[pas]+num[nxt];
    if((val-goal[pos])%wk==0) {
      num[pos]=goal[pos];
      ans+=(val-goal[pos])/wk;
      ll nnxt=(pos+2)%n;
      if(goal[nxt]!=num[nxt]&&num[pos]+num[nnxt]<num[nxt]) pque.push(P(num[nxt],nxt));

      ll ppst=(pos+n-2)%n;
      if(goal[pas]!=num[pas]&&num[pos]+num[ppst]<num[pas]) pque.push(P(num[pas],pas));
    }
    else{
      ll nval=val%wk;
      ans+=val/wk;
      if(nval<goal[pos]){
        cout<<-1<<endl;
        return 0;
      }
      else{
        num[pos]=nval;

        ll nnxt=(pos+2)%n;
        if(goal[nxt]!=num[nxt]&&num[pos]+num[nnxt]<num[nxt]) pque.push(P(num[nxt],nxt));

        ll ppst=(pos+n-2)%n;
        if(goal[pas]!=num[pas]&&num[pos]+num[ppst]<num[pas]) pque.push(P(num[pas],pas));
      }
    }
  }
  for(int i=0;i<n;i++){
    if(num[i]!=goal[i]) {
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<ans<<endl;
}
