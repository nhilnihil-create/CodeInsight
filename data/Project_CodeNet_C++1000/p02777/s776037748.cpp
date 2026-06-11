#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  string s, t, u;
  int a, b;
  cin >> s >> t >> a >> b >> u;
  if(u == s) a--;
  if(u == t) b--;
  printf("%d %d", a, b);
  return 0;
}