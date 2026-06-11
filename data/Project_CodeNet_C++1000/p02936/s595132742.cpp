#include <iostream>
#include <vector>

typedef long long ll;

std::vector<std::vector<ll> > Graph;

void dfs(ll now, ll root, std::vector<ll> &resa){
  for(int i = 0 ; i < (int)Graph[now].size() ; i++){
    if(Graph[now][i] != root){
      resa[Graph[now][i]] += resa[now];
      dfs(Graph[now][i], now, resa);
    }
  }

}

int main(){
  ll N, Q;
  std::cin >> N >> Q;
  Graph.assign(N, std::vector<ll>() );
  for(int i = 0 ; i < N - 1 ; i++){
    ll a, b;
    std::cin >> a >> b;
    Graph[a - 1].push_back(b - 1);
    Graph[b - 1].push_back(a - 1);
  }
  std::vector<ll> counter(N);
  for(int i = 0 ; i < Q ; i++){
    ll p, x;
    std::cin >> p >> x;
    counter[p - 1] += x;
  }
  
  dfs(0, -1, counter);

  for(auto && r : counter){
    std::cout << r << " ";
  }
  std::cout << std::endl;
  
  return 0;
}

