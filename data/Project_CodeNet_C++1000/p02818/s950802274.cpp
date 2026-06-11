#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long A, B, K; cin >> A >> B >> K;
  long long takahashi = max((long long)0, A - K);
  long long aoki = max((long long)0, min(B, A + B - K));
  cout << takahashi << " " << aoki << endl;
}