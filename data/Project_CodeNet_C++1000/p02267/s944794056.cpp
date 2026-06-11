#include <iostream>

#define MAX_N 10000
using namespace std;

int main()
{
  int s_len, t_len;
  int S[MAX_N], T[MAX_N];
  cin >> s_len;
  for (int i = 0; i < s_len; i++) {
    cin >> S[i];
  }
  cin >> t_len;
  for (int i = 0; i < t_len; i++) {
    cin >> T[i];
  }
  int n = 0;
  for (int i = 0; i < t_len; i++) {
    bool found = false;
    for (int j = 0; j < s_len; j++) {
      if (T[i] == S[j]) {
        found = true;
      }
    }
    if (found) {
      n++;
    }
  }
  cout << n << endl;
  return 0;
}