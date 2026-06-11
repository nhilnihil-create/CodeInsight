#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
  ll n,k,cur=1,count=0,check,span;
  cin >> n >> k;
  vector<ll> a(n+10),b(n+10,0);
  rep(i,n){
    cin >> a.at(i+1);
  }
  
  while(true){
    if(b.at(cur) == 1){
      check = count;
      b.at(cur)++;
      count++;
      cur = a.at(cur);
      break;
    }
    if(count == k){
      cout << cur << endl;
      return 0;
    }
    b.at(cur)++;
    count++;
    cur = a.at(cur);
  }
  while(true){
    if(b.at(cur) == 2){
      span = count - check;
      k = (k-count) % span;
      count = 0;
      // cur = a.at(cur);
      break;
    }
    if(count == k){
      cout << cur << endl;
      return 0;
    }
    b.at(cur)++;
    count++;
    cur = a.at(cur);
  }
  while(true){
    if(count == k){
      cout << cur << endl;
      return 0;
    }
    count++;
    cur = a.at(cur);
  }
  
  return 0;
}
