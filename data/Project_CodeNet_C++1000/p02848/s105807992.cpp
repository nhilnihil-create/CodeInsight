
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s;
  int n;
  cin >> n >> s;
  rep(i,s.size()){
    if(s[i] + n > 'Z'){
      s[i] = ((s[i] - 'A' + n) % 26) + 'A';
    }
    else s[i] = s[i] + n;
  }
  cout << s << endl;
  return 0;
}