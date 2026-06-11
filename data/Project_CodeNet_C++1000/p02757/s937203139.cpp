#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  ll N, P;
  string S;
  cin >> N >> P;
  cin >> S;

  ll ans = 0;
  reverse(S.begin(), S.end());
  if(P == 2){
    for(ll i = 0; i < N; i++){
      ll now = S[i] - '0';
      if(now % 2 == 0){
        ans += N - i;
      }
    }
    cout << ans << endl;
    return 0;
  }
  if(P == 5){
    for(ll i = 0; i < N; i++){
      ll now = S[i] - '0';
      if(now == 0 || now == 5){
        ans += N - i;
      }
    }
    cout << ans << endl;
    return 0;
  }

  vector<int> pow10_mod(N); // 10^i をPで割ったあまり
  for(int i = 0; i < N; i++){
    if(i == 0){
      pow10_mod[i] = 1;
    } else { 
      pow10_mod[i] = ( pow10_mod[i-1] * 10 ) % P;
    }
  }

  vector<ll> mod(N); // 部分数字列をPで割ったあまり
  for(ll i = 0; i < N; i++){
    if(i == 0){
      mod[i] = S[i] - '0';
      mod[i] %= P;
    } else { 
      ll now = S[i] - '0';
      // now * 10^i + mod[i-1] を Pで割ったあまりがほしい　
      ll tmp_mod = ( now * pow10_mod[i] ) % P ;
      tmp_mod += mod[i-1];
      tmp_mod %= P;
      mod[i] = tmp_mod;
    }
  }

  map<int, ll> m;
  for(auto x: mod){
    m[x]++;
  }
  for(auto x: m){
    // cerr << x.first << " " << x.second << endl;
    ans += (x.second * (x.second-1) / 2);
  }
  cout << ans + m[0] << endl;

  return 0;
}
