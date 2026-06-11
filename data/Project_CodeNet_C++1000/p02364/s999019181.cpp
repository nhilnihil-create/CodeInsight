#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#define INF 100000000
#define ll long long
using namespace std;

ll par[10000], rk[10000];

ll bitFind(ll x){
  if(x == par[x])
    return x;
  return par[x] = bitFind(par[x]);
}

ll bitSame(ll x, ll y){
  return bitFind(x) == bitFind(y);
}

void bitMerge(ll x, ll y){
  x = bitFind(x);
  y = bitFind(y);
  if(rk[x] < rk[y]){
    par[x] = y;
  }else if(rk[x] > rk[y]){
    par[y] = x;
  }else{
    par[x] = y;
    rk[y]++;
  }
}

int main(){
  ll V, E;
  cin >> V >> E;
  for(ll i = 0; i < V; i++){
    par[i]  = i;
    rk[i] = 0;
  }
  priority_queue< pair<ll, pair<ll,ll> >, vector< pair<ll, pair<ll,ll> > >, greater< pair<ll, pair<ll,ll> > > > pq;
  for(ll i = 0; i < E; i++){
    ll s,t,w;
    cin >> s >> t >> w;
    pq.push(make_pair(w,make_pair(s,t)));
  }
  ll cnt = 1;
  ll cost = 0;
  if(E == 0){
    cout << 0 << endl;
    return 0;
  }
  while(!pq.empty()){
    if(!bitSame(pq.top().second.first, pq.top().second.second)){
      bitMerge(pq.top().second.first, pq.top().second.second);
      cnt++;
      cost += pq.top().first;
    }

    if(cnt == V){
      cout << cost << endl;
      return 0;
    }
    pq.pop();
  }


}