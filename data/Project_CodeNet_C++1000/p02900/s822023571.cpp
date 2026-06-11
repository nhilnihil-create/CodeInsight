#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

vector<int> prime;

void enum_prime() {
  vector<bool> is_prime((int)1e6+1, true);
  for (int i = 2; i <= 1e6+1; ++i) {
    if (is_prime[i] == false) continue;
    prime.push_back(i);
    for (int j = 2*i; j <= 1e6+1; j += i) is_prime[j] = false;
  }
  return;
}

int main() {
  ll a, b;
  cin >> a >> b;
  ll g = gcd(a, b);
  enum_prime();
  int ans = 1;
  for (int i = 0; i < prime.size(); ++i) {
    if (g % prime[i] == 0) ++ans;
    while (g % prime[i] == 0) g /= prime[i];
  }
  if (g > 1) ++ans;
  cout << ans << endl;
  return 0;
}