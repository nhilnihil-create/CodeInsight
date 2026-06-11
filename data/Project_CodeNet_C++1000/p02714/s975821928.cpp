//R, G, B のみからなる、長さ N の文字列 S があります。
//以下の 2 つの条件をともに満たす組 (i, j, k) (1 ≤ j < k ≤ N)の数を求めてください。

//S_i ≠S_j かつ S_i≠S_k かつ S_j≠S_k である
//j−i≠k-j である

//解説通り書きました
//通り数を計算するときはこのやり方を使おう
#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i = 0; i < (n); ++i )
#define rep_rev(n,i) for(ll i = n; i >= 0; --i )
using namespace std;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
  int N,r = 0,g = 0,b = 0;
  ll p;
  string S; cin >> N >> S;
  vector<int> a(N);
  rep(i,N){
    if(S[i] == 'R') a[i] = 0;
    if(S[i] == 'G') a[i] = 1;
    if(S[i] == 'B') a[i] = 2;
  }
  vector<int> cnt(3);
  rep(i,N) cnt[a[i]]++;
  ll ans = 1;
  rep(i,3) ans *= cnt[i];
  for(int j = 0; j < N; ++j){
    for(int i = 0; i < j; ++i){
      int k = j + (j - i);
      if(k < N){
        if(S[i] == S[j]) continue;
        if(S[i] == S[k]) continue;
        if(S[j] == S[k]) continue;
        ans--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
