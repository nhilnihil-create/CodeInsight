#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
using namespace std;
typedef long long ll;
typedef pair <ll,ll> P;

int main(){
  ll n,k;
  cin>>n>>k;
  ll p[5005],c[5005];
  rep(i,n){
    cin>>p[i];
    p[i]--;
  }
  rep(i,n){
    cin>>c[i];
  }

  vector<P> cycle_cost(n,{-2,0});
  rep(st,n){
    if(cycle_cost[st].first!=-2) continue;
    ll now=p[st];
    ll score=c[st],cnt=1;
    while(now!=st){
      score+=c[now];
      cnt++;
      now=p[now];
    }
    if(score<0) score=-1;
    rep(i,cnt){
      cycle_cost[now].first=score;
      cycle_cost[now].second=cnt;
      now=p[now];
    }
  }

  /*
  for(auto x:cycle_cost){
    cout<<x.first<<' '<<x.second<<endl;
  }
  */
  
  ll ans=-1e18;
  rep(st,n){
    ll now=st;
    ll score=0;
    ll cnt=0;
    if(cycle_cost[now].first<0){
      rep(i,cycle_cost[st].second){
	if(cnt>=k) break;
	now=p[now];
	score+=c[now];
	ans=max(score,ans);
	cnt++;
      }
    }
    else{
      ans=max(cycle_cost[st].first*(k/cycle_cost[st].second),ans);
      rep(i,cycle_cost[st].second){
	if(cnt>=k) break;
	now=p[now];
	score+=c[now];
	cnt++;
	ll ma=score;
	ma+=cycle_cost[st].first*((k-cnt)/cycle_cost[st].second);
	ans=max(ma,ans);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
