// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

ll gcd3(ll a, ll b, ll c) {
  return gcd(gcd(a, b), c);
}
int main() {
  ll n; cin >> n;
  n++;
  ll sum = 0;
  loop(i,1,n) loop(j,1,n) loop(k,1,n) sum += gcd3(i,j,k);
  cout << sum << endl;
  return 0;
}
