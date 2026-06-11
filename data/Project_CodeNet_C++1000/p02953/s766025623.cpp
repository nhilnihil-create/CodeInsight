#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;
//階乗できるよ
ll kaizyo(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  ll n; cin >> n;
  vector<ll> h(n);
  rep(i,n) cin >> h.at(i);
  ll max_h = 0;
  

  rep(i,n) {
    
    if(h.at(i) - max_h < 0) {
      cout << "No" << endl;
      return 0;
    }
    
    h.at(i)--;
    max_h = max(max_h,h.at(i));
    
  }

  cout << "Yes" << endl;
}

