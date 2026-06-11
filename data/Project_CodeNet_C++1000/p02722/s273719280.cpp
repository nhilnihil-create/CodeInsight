#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
vector<long long> divisor(long long n){
    vector<long long> res;
    for(long long i = 1; i*i <= n; i++){
        if(n%i==0){
            res.push_back(i);
            if(n/i != i)res.push_back(n/i);
        }
    }
    return res;
}

int main() {
  ll n;
  cin >> n;
  auto div = divisor(n);


  auto ok = [&](ll x, ll cur){
    while (cur % x == 0) {
      cur /= x;
    }
    return cur % x == 1;
  };
  int res = 0;
  for (auto e : div) {
    if (e == 1) continue;
    res += ok(e, n);
  }

  auto div2 = divisor(n - 1);

  cout << res + div2.size() - 1 << endl;

  return 0;
} 