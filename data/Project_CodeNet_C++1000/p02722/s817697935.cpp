#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

ll INF = 1ll << 60;

void div(ll n, queue<ll> &que){
  for(ll i = 1; i*i <= n; i++){
    if(n%i == 0){
      que.push(i);
      if(n != i*i){
        que.push(n/i);
      }
    }
  }
  return;
}

int main(){
  ll n;
  cin >> n;
  
  ll cnt = 0;
  
  queue<ll> que;
  div(n-1, que);
  while(que.size() > 0){
    if(n%que.front() == 1)
      cnt++;
    que.pop();
  }
  
  div(n, que);
  while(que.size() > 0){
    ll num = n;
    ll k = que.front();
    if(k == 1){
      que.pop();
      continue;
    }
    while(num%k == 0 && num >= k){
      num /= k;
    }
    if(num%k == 1){
      cnt ++;
    }
    que.pop();
  }
  
  cout << cnt << endl;
  
  return 0;
  
}