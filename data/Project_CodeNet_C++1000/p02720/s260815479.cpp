#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  ll n;
  cin >> n;
  queue<ll> q;
  rep(i,9){
    q.push(i+1);
  }
  ll count = 0;
  while(1){
    ll x;
    x = q.front();
    count++;
    if(count == n){
      cout << x;
      return 0;
    }
    q.pop();
    if(x % 10 == 0){
      q.push(x*10);
      q.push(x*10+1);
    }
    else if(x % 10 == 9){
      q.push(x*10+8);
      q.push(x*10+9);
    }
    else{
      ll a;
      a = x % 10;
      q.push(x*10+a-1);
      q.push(x*10+a);
      q.push(x*10+a+1);
    }
  }
    
  return 0;
}