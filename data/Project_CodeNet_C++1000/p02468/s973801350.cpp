#include <iostream>
 
using namespace std;
 
typedef long long ll;
 
ll pow(ll m, ll n, int M) {
  if (n == 0) return 1;
  if (n & 1) return pow(m * m % M, n >> 1, M) * m % M;
  return pow(m * m % M, n >> 1, M);
}
 
int main() {
  ll m, n;
  cin >> m >> n;
  cout << pow(m, n, 1000000007) << endl;
  return 0;
}