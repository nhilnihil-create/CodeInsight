#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;

//階乗関数　ATCODER_AMARIに注意
ll factorial(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    //sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  ll n;
  cin >> n;
  std::vector<ll> l(n);

  rep(i,n) cin >> l.at(i);

  sort(l.begin(), l.end());

  ll count = 0;

  for(ll a = 0; a < n; a++) {
    for(ll b = a + 1; b < n; b++) {
      for(ll c = b + 1; c < n; c++) {
        if(l.at(a) < l.at(b) + l.at(c) && l.at(b) < l.at(c) + l.at(a) && l.at(c) < l.at(a) + l.at(b)) {
          count++;
        }
      }
    }
  }

  cout << count << endl;
}
