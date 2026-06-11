#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  int N;
  cin >> N;

  string S;
  cin >> S;

  int num = 0;
  int count = 0;
  rep(i, S.size()) if (S[i] == 'R') num++;
  rep(i, num) if (S[i] == 'R') count++;

  cout << num - count << endl;
}