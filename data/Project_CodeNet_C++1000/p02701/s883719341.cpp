#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll N,i;
  string S;
  ll ans = 0;
  map<string,ll> memo;
  cin >> N;
  for(i=0;i<=N-1;i++){
    cin >> S;
    memo[S] = 1;
  }
  for(auto&& x : memo) ans += memo[S];
  cout << ans << endl;
}

