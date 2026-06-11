#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
bool prime[10000000];



int main() {
  ll s;
  cin >> s;

  const ll v = 1e9;

  ll x = (v - s % v) % v;
  ll y = (s + x) / v;

  cout << "0 0 1000000000 1 "<<x<<" "<<y<<endl;
}
