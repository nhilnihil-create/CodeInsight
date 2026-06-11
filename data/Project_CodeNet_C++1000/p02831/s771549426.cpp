#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ll A, B;
  cin >> A >> B;
  cout << A * B / __gcd(A, B) << "\n";
}
