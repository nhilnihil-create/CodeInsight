#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// 必ず働く日にちを全列挙する問題
// K日働くことができるかどうか → 貪欲法(左端から選んでいく。それでK日選べなかったら絶対に無理)
// 1, 2, 3, …, Kと書けるかどうか。書けるなら可能、書けないなら不可能。
// 元々K日働くことが可能なケースで、働ける特定のある日を働けない日としたとき不可能となったのなら、その日は必ず働く日になる
// 左端から貪欲で詰めていった場合、右端から貪欲で詰めていった場合をそれぞれ計算する。
// 左端から詰めていって書いた番号と、右端から詰めていって書いた番号が一致する場合、その日は必ず働く日になる。
// 左からの貪欲と右からの貪欲で解ける。

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K, C; cin >> N >> K >> C;
  string S; cin >> S;
  vector<int> L(N, 0);
  vector<int> R(N, -1);
  int l = -1, r = N;
  int cntL = 1, cntR = K;
  REP(i, N){
    if(S[i] == 'o' && i > l){
      L[i] = cntL;
      l = i + C;
      cntL++;
    }
    if(S[N-1-i] == 'o' && N-1-i < r){
      R[N-1-i] = cntR;
      r = (N-1-i) - C;
      cntR--;
      if(cntR ==  0) cntR--;
    }
  }
  vector<int> ans;
  REP(i, N){
    if(L[i] == R[i]){
      ans.push_back(i+1);
    }
  }
  for(auto &i : ans){
    cout << i << endl;
  }
}