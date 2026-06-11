#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

typedef long long ll;

int main() {
  ll a, b, n;
  cin >> a >> b >> n;
  
  ll x = (b - 1 <= n ? b - 1 : n); 
  cout << a * x / b - a * (x / b) << endl;
  return 0;
}