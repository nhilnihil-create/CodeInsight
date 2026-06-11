#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
const int MOD = 1000000007;

long long mod(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
  string ans;
  int N,K,Q;
  cin >> N >> K >> Q;
  vector<int> A(Q),P(N,K-Q);
  rep(i,Q) cin >> A[i];
  map<int, int> cnt;
  for (int x : A) {
    if (cnt.count(x-1)) {
      // 既に含まれているならインクリメント
      cnt.at(x-1)++;
    } else {
      // 含まれていないなら、1を追加
      cnt[x-1] = 1;
    }
  }
  
  for(int i=0;i<cnt.size();i++) {
    P[i] += cnt[i];
  }
  rep(i,N){
    if(P[i]>0) ans="Yes";
    else ans = "No";
    cout << ans << endl;
  }
  
  return 0;
}
