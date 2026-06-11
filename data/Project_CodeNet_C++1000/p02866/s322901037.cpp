#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

// n^r%modを出力
long long mod_pow(long long n, long long r, long long mod){
  long long ret = 1;
  while(r > 0){
    if(r & 1)
      ret = (ret*n)%mod;
    r >>= 1;
    n = n*n%mod;
  }
  return ret;
}


int main(){
  long long N;
  cin >> N;
  pair<long long, long long> p[N];
  long long tmp;
  rep(i, N){
    cin >> tmp;
    p[i] = make_pair(tmp, i);
  }
  // 入力終了

 // 距離0の頂点は絶対ある(頂点1)                                               
  if(p[0].first != 0){
    cout << 0 << endl;
    return 0;
  }
  
  // 距離が短い順にソート
  sort(p, p+N);

  // 距離0の頂点はただ1つ(頂点1のみ)
  if(p[0].first == 0 && p[1].first == 0){
    cout << 0 << endl;
    return 0;
  }

  long long ans = 1;
  long long MOD = 998244353;
  
  // 距離が小さい頂点から順に見ていく
  // number of current vertex, number of previous vertex
  long long curr_vnum = 0, prev_vnum = 1;

  long long i = 1;
  while(i<N){
    curr_vnum = 1;
    // 距離がいきなり2以上飛ぶことはない
    if(p[i-1].first+1 != p[i].first){
      cout << 0 << endl;
      return 0;
    }
    
    // 頂点1からの距離が同じものをまとめて見る
    while(p[i].first == p[i+1].first){
      i++;
      curr_vnum++;
    }

    // 今見ている頂点を，1つ前に見ていた頂点のどれかにつけるため
    // prev^currだけ増えていく
    ans = ans*mod_pow(prev_vnum, curr_vnum, MOD);
    ans = ans % MOD;
    
    // prevの更新
    prev_vnum = curr_vnum;
    
    i++;
  }
  
  // 解答
  cout << ans << endl;
  
  return 0;
}
