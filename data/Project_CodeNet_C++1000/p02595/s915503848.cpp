#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, D;
  cin >> N >> D;
  
  vector<pair<long long, long long>> p(N);
  for (long long i = 0; i < N; i++) {
    long long a, b;
    cin >> a >> b;
    p.at(i) = make_pair(a, b);
  }
  
  vector<long long> l(N);
  for (long long i = 0; i < N; i++) {
    l.at(i) = p.at(i).first * p.at(i).first + p.at(i).second * p.at(i).second;
  }
  
  long long ans = 0;
  for (long long i = 0; i < N; i++) {
    if (l.at(i) <= D * D) {
      ans++;
    }
  }
  
  cout << ans << endl;
}
