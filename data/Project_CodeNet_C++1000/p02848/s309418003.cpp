#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  for (int i = 0; i < (int)S.size(); i++) {
    int ne = (S[i] - 'A' + N) % 26;
    S[i] = ne + 'A';
  }
  cout << S << endl;
  return 0;
}