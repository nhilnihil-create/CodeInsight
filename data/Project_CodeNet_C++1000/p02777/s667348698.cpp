#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{

  string s, t;
  cin >> s >> t;
  int a, b;
  cin >> a >> b;

  string ans;
  cin >> ans;

  if(ans == t){
    cout << a << ' ' << b - 1;
  }
  else if(ans == s)
    cout << a-1 << ' ' << b;
}
