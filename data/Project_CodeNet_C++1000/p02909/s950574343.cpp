#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
string _S[3] = {"Sunny", "Cloudy", "Rainy"};
int main() {
  string s;
  cin >> s;
  int id;
  REP(i, 3) {
    if (_S[i] == s) id = i;
  }
  cout << _S[(id + 1) % 3] << endl;
}