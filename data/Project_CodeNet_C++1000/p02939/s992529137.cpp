#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  string s;
  cin >> s;
 
  set<string> v;
 
  string x = "";
  string prev = "";
  int ans = 0;
  rep(i,s.size()) {
    x.push_back(s[i]);
    if (x == prev) continue;
    prev = x;
    x = "";
    ans++;
  }
 
  cout << ans << endl;
  return 0;
}