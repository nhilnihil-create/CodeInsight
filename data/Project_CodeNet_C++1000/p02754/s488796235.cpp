#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  
  ll aa = N/(A+B);
  ll bb = N%(A+B);

  cout << aa*A+min(A, bb) << endl;
  
  return 0;
}