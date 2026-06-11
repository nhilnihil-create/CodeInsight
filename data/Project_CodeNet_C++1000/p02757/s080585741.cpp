#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

int ctoi(char c) {
  if( c >= '0' && c <= '9' ) return c-'0';
  else return -1;
}


signed main() {
  
  int N, P;
  cin >> N >> P;
  
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  
  if( P == 2 || P == 5 ){
    int ans = 0;
    for( int i = 0; i < N; i++ ){
      if( ctoi(S.at(i)) % P == 0 ) ans += N-i;
    }
    cout << ans << endl;
    return 0;
  }
  
  map<int, int> amari;
  amari[0] = 1;
  
  int now = 0;
  int keta = 1;
  for( int i = 0; i < N; i++ ){
    now += ctoi(S.at(i))*keta;
    now %= P;
    if( amari.count(now) ) amari[now]++;
    else amari[now] = 1;
    keta *= 10;
    keta %= P;
  }
  
  int ans = 0;
  for( auto p : amari ){
    ans += p.second * (p.second-1) / 2;
  }
  cout << ans << endl;
}