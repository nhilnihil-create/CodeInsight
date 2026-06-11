#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, K;
  cin >> N >> K;
  vector<vector<int64_t>> G(N,vector<int64_t>(0));
  for(int i=0; i<N-1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  
  int64_t ans = K;
  vector<bool> seen(N,false);
  seen.at(0) = true;
  queue<int> Q;
  Q.push(0);
  int64_t MOD = 1e9+7;
  
  while(Q.size()){
    int64_t x = Q.front();
    Q.pop();
    int64_t cnt = K-1;
    if(x != 0){
      cnt--;
    }
    for(int i=0; i<G.at(x).size(); i++){
      if(!seen.at(G.at(x).at(i))){
        ans *= cnt;
        ans %= MOD;
        cnt--;
        Q.push(G.at(x).at(i));
        seen.at(G.at(x).at(i)) = true;
        //cout << ans << " " << x << endl;
      }
    }
  }
  cout << ans << endl;
}