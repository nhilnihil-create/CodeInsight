#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  string s;
  cin>>n>>s;
  
  s.erase(unique(ALL(s)),s.end());
  cout<<s.size()<<endl;
  
  return 0;
}