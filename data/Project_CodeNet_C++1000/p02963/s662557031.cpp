#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
bool prime[10000000];



int main() {
  ll s;
  cin >> s;

  const ll v = 1e9;

  ll x = (v - s % v);
  ll xx = x % v;
  ll y = (s + xx) / v;

  if(x < 0) cout << "iji"<<endl;

  cout << "0 0 1000000000 1 "<<xx<<" "<<y<<endl;
}
