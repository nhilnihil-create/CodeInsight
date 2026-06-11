#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;
ll n;
vector<vector<ll>> edge;
vector<ll> parent;
vector<ll> color;
map<P, ll> m;

void make_parent(int cur){
  for (auto p : edge[cur]){
    if (parent[p] == -1){
      parent[p] = cur;
      make_parent(p);
    }
  }
}

void allocate_color(int cur){
  if (parent[cur] == -1){
    ll now_c = 1;
    for (auto child : edge[cur]){
      color[m[P(cur, child)]] = now_c;
      now_c++;
      allocate_color(child);
    }
  }
  else {
    ll c = color[m[P(parent[cur], cur)]];
    ll now_c = 1;
    for (auto child : edge[cur]){

      if (child == parent[cur])
        continue;

      if (now_c == c){
        now_c++;
      }
      color[m[P(cur, child)]] = now_c;
      now_c++;
      allocate_color(child);
    }
  }
}

int main(void){
  cin >> n;
  edge = vector<vector<ll>>(n, vector<ll>(0));
  parent = vector<ll>(n, -1);
  color = vector<ll>(n, -1);

  for (ll i = 0; i < n-1; i++){
    ll a, b;
    cin >> a >> b;
    
    a--; b--;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
    m[P(a, b)] = i;
    m[P(b, a)] = i;
  }
  ll k = 0;
  for (ll i = 0; i < n; i++){
    k = max(k, (ll)edge[i].size());
  }


  make_parent(0);
  parent[0] = -1;


  allocate_color(0);



  cout << k << endl;
  for (ll i = 0; i < n-1; i++){
    cout << color[i] << endl;
  }

  return 0;
}
