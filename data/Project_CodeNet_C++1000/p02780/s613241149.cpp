#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG

/*
 // 深さ優先探索
vector<bool> seen;
int dfs(const Graph &G, ll v) {
    seen[v] = true; // v を訪問済にする
    int score = 0; 

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー

        // 負荷さ優先探索中の処理



        dfs(G, next_v); // 再帰的に探索, 毎回mat渡してええの？
    }
    return score;
} */

/*
//桁数の計算
ll keta(ll num){
  ll ans= 0 ;
  ll rem;

  for (ll i = 4; i >= 0 ; i--){
    rem = pow(10,i);
    ans += (num / rem); 
    num = num % rem;
  }
  return ans;
}
*/


int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> p(N);
  //vector<vector<int>> data(3, vector<int>(4));
  for (ll i=0; i<N;i++){
    cin >> p[i];
  }

  ll max = 0;
  ll save = 200007;
  ll tmp =0;
  for (ll i=0; i<N-K+1;i++){
    if(i==0){
      for (ll j=0; j<K; j++){
        tmp += p[i+j];
      }
    }else{
      tmp = tmp - p[i-1] + p[i+K-1];
    }
    
    if(tmp > max){
      save = i;
      max = tmp;
    }
  }
  long double ans = 0.0;

  for(ll i=save; i< save + K; i++){
    ans += ((long double)p[i] + 1.0) / 2.0; 
  }

  cout << setprecision(7) << (long double)ans << endl;

  return 0;
}
