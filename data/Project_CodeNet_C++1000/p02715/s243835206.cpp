#include <bits/stdc++.h>

const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

const int mod=1000000007;
int N,K;
long ans;
vector<long> X(100100); //引き算する分を保存する配列
// https://h1guch.hatenablog.com/entry/2020/04/13/174426

//繰り返し二乗法
//a^n mod m を返す
long power(long a, long n, long m) {
  long ret = 1;
  for (; n > 0; n >>= 1, a = a * a % m) {
    if (n % 2 == 1) {
      ret = ret * a % m;
    }
  }
  return ret;
}

//ｎの約数をpush_backしたvectorを返す
vector<long> divisor(long n)
{
  vector<long> res;
  for(long i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      res.push_back(i);
      if(i * i != n) res.push_back(n / i);
    }
  }
  sort(res.begin(), res.begin());
  return res;
}

int main() {
  cin >> N >> K;

  //Kからの降順にした
  for(int i = K; i > 0; i--) {
    //X[i]が引き算する分
    //i=Kでは当然X[i]=0
    long cnt = ((power(K/i, N, mod) - X[i]) % mod + mod) % mod;

    //最大公約数がｉである数列の個数がcnt個と分かった
    ans = (ans + i * cnt + mod) % mod;

    vector<long> d = divisor(i);
    //約数の子たちのために引き算する分を教えてあげている
    for(auto &it : d) {
      X[it] = (X[it] + cnt + mod) % mod;
    }
  }

  cout << ans << endl;
  return 0;
}