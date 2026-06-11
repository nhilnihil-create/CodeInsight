#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

int main(){
  string s, t, u;
  int a, b;
  cin >> s >> t >> a >> b >> u;
  
  if(s == u)
    a--;
  else
    b --;
  
  cout << a << " " << b << endl;
  
  return 0;
  
}