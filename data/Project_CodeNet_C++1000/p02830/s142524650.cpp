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
  int n;cin >> n;
  vector<char> ans(2*n);
  rep(i,n) {
    char s; cin >> s;
    ans.at(2*i) = s;
  }
  rep(i,n){
    char t;cin >> t;
    ans.at(2*i + 1) = t;
  }
rep(i,2*n){
  cout << ans.at(i);
}
cout << endl;
  
}
