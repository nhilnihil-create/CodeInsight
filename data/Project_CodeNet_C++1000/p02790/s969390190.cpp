#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;
using Graph = vector<vector<int>>;

int main() {
  int a, b;
  cin >> a >> b;
  int num_min = min(a, b);
  int num_max = max(a, b);

  rep (i, num_max) cout << num_min;
  cout << endl;
  // char in[110];
  // rep (i, b) in[i] = '0' + a;
  // cout << in << endl;
  // string L = in;
  // rep (i, a) in[i] = '0' + b;
  // cout << in << endl;
  // in[a] = 0;
  // cout << in << endl;
  // string R = in;
  // cout << min(L, R).c_str() << endl;
  return 0;
}