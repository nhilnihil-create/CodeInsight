#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
#define INF (1e9)

int main() {
  ll N;
  cin >> N;
  bool ans = true;
  ll a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    if (a % 2 != 0) continue;
    if (a % 3 != 0 && a % 5 != 0) ans = false;
  }

  if (ans)
    cout << "APPROVED" << endl;
  else
    cout << "DENIED" << endl;
}
