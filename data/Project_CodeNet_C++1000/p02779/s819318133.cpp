#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  set<int> s(a.begin(), a.end());
  if(s.size() == a.size()) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}