#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int>a(n);
  vector<int>p(n);
  vector<int>q(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];

  rep(i, n) a[i]=i+1;
  map<vector<int>,int> mp;
  int i = 0;
  do {
    mp[a] = ++i;
  }
  while(next_permutation(a.begin(), a.end()));
  cout << abs(mp[p]-mp[q]) << endl;
  return 0;
}