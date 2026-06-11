#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll a,b,k;
  cin >> a >> b >> k;
  ll a_eat = min(a,k);
  a -= a_eat;
  k -= a_eat;
  ll b_eat = min(b,k);
  b -= b_eat;
  k -= a_eat;
  cout << a << " " << b << endl;

}
