#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int main() {
  int n,d,a;
  cin>>n>>d>>a;
  P memo[n];
  for(int i=0;i<n;i++){
    int x,h;
    cin>>x>>h;
    h=(h+a-1)/a;
    memo[i]=make_pair(x,h);
  }
  sort(memo,memo+n);
  ll ans=0;
  queue<llP> que;
  ll x,h,tmp=0,cnt=0;
  for(int i=0;i<n;i++){
    x=memo[i].first;
    while(!que.empty()){
      if(que.front().first<x){
        tmp-=que.front().second;
        que.pop();
      }
      else break;
    }
    h=memo[i].second-tmp;
    if(h<=0) cnt=0;
    else cnt=h;
    que.push(make_pair(x+2*d,cnt));
    tmp+=cnt;
    ans+=cnt;
  }
  cout<<ans<<endl;
  return 0;
}