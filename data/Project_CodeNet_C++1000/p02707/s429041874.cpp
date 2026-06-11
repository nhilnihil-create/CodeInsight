#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[N];
  A[0] = 0;
  int out[N];
  fill(out, out + N, 0);
  for (int i = 0; i < N - 1; i++) {
    cin >> A[i];
    out[A[i]-1]++;
  }

 for (int i = 0; i < N; i++) {
   cout << out[i] << endl;
 }
}

