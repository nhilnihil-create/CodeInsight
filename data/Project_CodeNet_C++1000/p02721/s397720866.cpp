#include<iostream>
#include<string>
using namespace std;

int main() {
  int N, K, C; string S; cin >> N >> K >> C >> S;
  bool f[N], l[N]; for (int i = 0; i < N; i++) f[i] = l[i] = false;
  int d = 0, m = 0;
  while (d < N) {
    if (S[d] == 'x') { d++; continue; }
    f[d] = true; m++; d += C + 1;
  }
  if (m > K) cout << endl;
  else {
    d = N - 1;
    while (d >= 0) {
      if (S[d] == 'x') { d--; continue; }
      l[d] = true; d -= C + 1;
    }
    for (int i = 0; i < N; i++)
      if (f[i] && l[i])
        cout << i + 1 << endl;
  }
}
