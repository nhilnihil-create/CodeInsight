#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];
  vector<int> v(n);
  rep(i, n) v[i] = i+1;
  map<vector<int>, int> m;
  int count = 1;
  do {
    m[v] = count;
    count++;
  } while (next_permutation(v.begin(), v.end()));
  cout << abs(m[p] - m[q]) << endl;
  return 0;
}