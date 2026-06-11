#include <iostream>
using namespace std;

int main() {
  long long N; cin >> N;
  long long R; cin >> R;
  
  if (N >= 10) cout << R << endl;
  else cout << R + 100 * (10 - N) << endl;
}