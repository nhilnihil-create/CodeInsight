#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

int main(){
  string s,t;
  cin >> s >> t;

  int a,b;
  cin >> a >> b;

  string u;
  cin >> u;
  if (u == s) a--;
  else if (u == t) b--;

  cout << a << " " << b << endl;
}
