#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ll INF = LLONG_MAX;
constexpr double DINF = DBL_MAX;
constexpr ll mod = 1e9+7;
constexpr double PI = M_PI;

template<typename T>
vector<T> make_v(size_t a){
  return vector<T>(a);
}
 
template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
 
  long long n;
  cin >> n;
  vector<ll> a(n-1), b(n-1);
  vector<vector<ll> > graph(n);
  map<pair<ll, ll>, int> mp;
  for(int i = 0; i < n-1; i++){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
    mp[make_pair(a[i], b[i])]++;
  }
  int k = 0;
  for(int i = 0; i < n; i++){
    k = max(k, (int)graph[i].size());
  }
  queue<pair<ll, int> > que;
  vector<bool> visited(n, false);
  que.push(make_pair(0, -1));
  while(!que.empty()){
    int now = que.front().first;
    int precol = que.front().second;
    que.pop();
    visited[now] = true;
    int nextcol = 0;
    for(int i = 0; i < (int)graph[now].size(); i++){
      long long next = graph[now][i];
      if(!visited[next]){
        nextcol++;
        if(nextcol == precol) nextcol++;
        que.push(make_pair(next, nextcol));
        if(mp[make_pair(now, next)] == 1){
          mp[make_pair(now, next)] = nextcol;
        }else{
          mp[make_pair(now, next)] = nextcol;
        }
      }
    }
  }
  cout << k << endl;
  for(int i = 0; i < n-1; i++){
    cout << mp[make_pair(a[i], b[i])] << endl;
  }
  return 0;
}
