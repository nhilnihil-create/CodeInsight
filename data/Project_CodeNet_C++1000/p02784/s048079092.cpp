#include <iostream>
using namespace std;

int main() {
  long long A, N;
  cin >> A >> N;
  long long S = 0;
  for (int i = 0; i < N; ++i) {
    long long a; cin >> a; S+= a;
  }
  if (S >= A) cout << "Yes" << endl;
  else cout << "No" << endl;
}