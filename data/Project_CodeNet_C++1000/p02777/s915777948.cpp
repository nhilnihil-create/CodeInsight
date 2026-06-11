#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string a, s[2];
  int x[2];
  cin >> s[0] >> s[1];
  cin >> x[0] >> x[1];
  cin >> a;
  if (a == s[0]){
    x[0]--;
  }
  else {
    x[1]--;
  }
  cout << x[0] << " " << x[1] << endl;
  return 0;
}
