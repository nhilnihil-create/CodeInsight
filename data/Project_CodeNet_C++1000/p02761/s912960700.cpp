#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N, M;
  cin >> N >> M;

  if(M == 0){
    if(N == 1){
      cout << 0 << "\n";
    } else{
      cout << (ll)pow(10, N - 1) << "\n";
    }

    return 0;
  }
  
  vl s(M), c(M);
  rep(i, M) cin >> s[i] >> c[i];

  map<ll, ll> num;
  rep2(i, 1, 10) num[i] = -1;

  rep(i, M){
    if((num[s[i]] > -1) && (num[s[i]] != c[i])){
      cout << -1 << "\n";
      return 0;
    }
    if((s[i] == 1) && (c[i] == 0) && (N > 1)){
      cout << -1 << "\n";
      return 0;
    }
    num[s[i]] = c[i];
  }

  rep2(i, 1, N + 1){
    if(num[i] > -1){
      cout << num[i];
    } else{
      if(i == 1)
	cout << 1;
      else
	cout << 0;
    }
  }

  cout << "\n";
  
  return 0;
}
