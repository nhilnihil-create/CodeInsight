#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> p(n),q(n);
  rep(i,0,n) cin >> p[i];
  rep(i,0,n) cin >> q[i];
  vector<int> array(n,0);
  rep(i,0,n) array[i] = i+1;
  int cnt = 0;
  int a,b;
  do {
    if (array == p) a = cnt;
    if (array == q) b = cnt;
    cnt++;
  } while (next_permutation(array.begin(), array.end()));
  cout << abs(a - b) << endl;
  return 0;
}
