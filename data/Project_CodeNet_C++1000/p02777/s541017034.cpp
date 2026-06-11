#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  string s, t;
  cin >> s >> t;
  int a, b;
  cin >> a >> b;
  map<string, int> mp;
  mp[s] = a;
  mp[t] = b;
  string u;
  cin >> u;
  mp[u]--;
  cout << mp[s] << " " << mp[t] << endl;
  return 0;
}