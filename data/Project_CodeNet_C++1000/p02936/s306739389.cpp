#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N,Q;
  cin >> N >> Q;
  vector<vector<ll>> Graph(N);
  for(ll i=0;i<N-1;i++){
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }
  map<ll,ll> Point;
  for(ll i=0;i<Q;i++){
    ll p,x;
    cin >> p >> x;
    p--;
    Point[p]+=x;
  }
  vector<ll> ans(N,-1);
  stack<ll> stack;
  stack.push(0);
  while(stack.size()!=0){
    ll state=stack.top();
    stack.pop();
    ans[state]=Point[state];
    for(ll y:Graph[state]){
      if(ans[y]!=-1){
        continue;
      }
      Point[y]+=Point[state];
      stack.push(y);
    }
  }
  for(ll i=0;i<N;i++){
    if(i!=N-1){
      cout << ans[i] << " ";
    }
    else{
      cout << ans[i] << endl;
    }
  }
}