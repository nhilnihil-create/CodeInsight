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

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}


int main() {
  ll n;
  cin >> n;

  if(n == 1) {
    cout << 0 << endl;
    return 0;
  }

  const auto &res = prime_factorize(n);

  const auto r_size = res.size();

  // for(auto p : res) {
  //   for(int i = 0; i < p.second; i++) cout << p.first << ' ';
  // }

  ll ans = 0;

  rep(i,r_size) {
    ll tmp = res.at(i).second;
    ll count = 1;
    
    while(tmp >= count) {
      tmp -= count;
      count++;
      ans++;
    }
  }

  cout << ans << endl;
}
