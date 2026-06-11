#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int n; 

void dfs(string s, char mx) {
  int l = s.length();
  if(l==n) {
    cout << s << endl;
    return;
  }
  for(char c = 'a'; c < mx; c++) dfs(s + c, mx);
  dfs(s + mx,(char)(mx + 1));

}

int main() {
  cin >> n;
  dfs("",'a');
  return 0;
}