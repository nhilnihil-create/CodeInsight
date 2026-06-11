#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC131 E-Friendships
// 完全グラフで下限:0 (全部の頂点を結べば距離が1)
// 上限はスター:(N-1)(N-2)/2 

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K; cin >> N >> K;
  if(K > (N-1)*(N-2)/2){
    cout << -1 << endl;
    return 0;
  }
  cout << (N-1) + ((N-1)*(N-2)/2)-K << endl;

  REP(i, N-1){  // スターを作る
    cout << 1 << " " << i+2 << endl;
  }

  int idx = 2, cnt = 1;
  REP(i, ((N-1)*(N-2)/2)-K){  //　Kの数に合わせるため距離2を潰す
    if(idx+cnt > N){
      idx = idx+1;
      cnt = 1;
    }
    cout << idx << " " << idx+cnt << endl;
    cnt++;
  }
}