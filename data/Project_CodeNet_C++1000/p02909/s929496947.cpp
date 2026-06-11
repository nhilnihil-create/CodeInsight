#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
  string S;
  cin >> S;
  if (S[0] == 'S') cout << "Cloudy" << endl;
  if (S[0] == 'C') cout << "Rainy" << endl;
  if (S[0] == 'R') cout << "Sunny" << endl;
}
