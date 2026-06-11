#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  string S;
  cin >> S;

  int count = 0;
  for (int i = 0; i < 1000; i++) {
    ostringstream sout;
    sout << setfill('0') << setw(3) << i;
    string pin = sout.str();
    int j = 0;
    while (j < N) {
      if (pin[0] == S[j]) {
        j++;
        while (j < N) {
          if (pin[1] == S[j]) {
            j++;
            while (j < N) {
              if (pin[2] == S[j]) {
                count++;
                j = N;
              }
              j++;
            }
          }
          j++;
        }
      }
      j++;
    }
  }

  cout << count << endl;

  return 0;
}
