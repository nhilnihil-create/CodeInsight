#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Bsort(a) sort(a.begin(), a.end(), greater<ll>())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ll a, b, c;
  cin >> a >> b >> c;
  if (a+b-c < 0 && (a+b-c)*(a+b-c) > 4*a*b) {
    cout << "Yes" << '\n';
  }
  else {
    cout << "No" << '\n';
  }
}