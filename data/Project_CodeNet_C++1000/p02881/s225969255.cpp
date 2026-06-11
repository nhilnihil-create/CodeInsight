#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;

vector<long long> enum_divisors(long long N) {
  vector<long long> res;
  for (long long i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      // 重複しないならば i の相方である N/i も push
      if (N / i != i) res.push_back(N / i);
    }
  }
  // 小さい順に並び替える
  sort(res.begin(), res.end());
  return res;
}

int main(){
    ll N;
    cin >> N;
    const auto &res = enum_divisors(N);
    ll out = 0;
    if (res.size() % 2 == 0) {
      ll x = res[res.size() / 2 - 1];
      ll y = res[res.size() / 2];
      out = x + y - 2;
    }
    else{
      out = res[res.size() / 2] * 2 - 2;
    }
    cout << out << endl;
    return 0;
}