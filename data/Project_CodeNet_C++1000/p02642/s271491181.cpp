#include <bits/stdc++.h>
using namespace std;

void mkprimes(int64_t N, vector<int64_t> &primes) {
  vector<bool> isprime(N + 1);
  for (int64_t i = 0; i <= N; i++) {
    isprime[i] = true;
  }
  isprime[0] = false;
  isprime[1] = false;

  for (int64_t i = 2; i <= N; i++) {
    if (isprime[i]) {
      primes.push_back(i);
      for (int64_t j = 2 * i; j <= N; j += i) {  // 素数iの倍数は素数ではない
        isprime[j] = false;
      }
    }
  }
}

int main() {
  int64_t N;
  cin >> N;
  map<int64_t, int64_t> uniq;
  // map<int, int> uniq;
  for (int64_t i = 0; i < N; i++) {
    int64_t x;
    cin >> x;
    if (uniq.count(x) == 0) {
      uniq[x] = 0;
    }
    uniq[x]++;
  }

  // エラトステネスのふるい風味
  vector<int64_t> search;
  unordered_set<int64_t> isprime;
  for (auto x : uniq) {
    search.push_back(x.first);
    isprime.insert(x.first);
  }

  sort(search.begin(), search.end());
  int64_t maxnum = search[search.size() - 1];

  vector<int64_t> primes;
  for (auto s : search) {
    if (isprime.count(s) > 0) {
      primes.push_back(s);
      for (int64_t j = 2 * s; j <= maxnum; j += s) {
        isprime.erase(j);
      }
    }
  }

  int64_t result = 0;
  for (auto pr : primes) {
    if (uniq.at(pr) == 1) {
      result++;
    }
  }
  cout << result << endl;
}
