#include <iostream>
using namespace std;
int main() {
  long long A, V, B, W, T;
  cin >> A >> V >> B >> W >> T;
  cout << (abs(B - A) <= T * (V - W) ? "YES" : "NO") << endl;
}
