#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC161 D - Lunlun Number
// 2020.06.24

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll K; cin >> K;
  queue<ll> q;
  for(ll i = 1; i <= 9; i++){
    q.push(i);
  }
  ll cnt = 1;
  while(1){
    ll cur = q.front(); q.pop();
    if(cur%10 != 0) q.push(cur*10+((cur%10)-1));
    q.push(cur*10+(cur%10));
    if(cur%10 != 9) q.push(cur*10+((cur%10)+1));
    if(cnt == K){
      cout << cur << endl;
      return 0;
    }
    cnt++;
  }
}