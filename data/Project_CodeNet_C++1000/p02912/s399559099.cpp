#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,m;
  cin >> n >> m;
  priority_queue<ll> que;
  rep(i,n){
    ll a;
    cin >> a;
    que.push(a);
  }
  ll ans=0;
  rep(i,m){
    ll cp=que.top();
    que.pop();
    cp/=2;
    que.push(cp);
  }
  while(!que.empty()){
    ll cp=que.top();
    que.pop();
    ans+=cp;
  }
  cout << ans;
}