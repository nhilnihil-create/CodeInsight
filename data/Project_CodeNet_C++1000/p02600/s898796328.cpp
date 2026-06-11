#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main()
{
  int x;
  cin >> x;
  if(x < 600) cout << '8' << endl;
  else if(x < 800) cout << '7' << endl;
  else if(x < 1000) cout << '6' << endl;
  else if(x < 1200) cout << '5' << endl;
  else if(x < 1400) cout << '4' << endl;
  else if(x < 1600) cout << '3' << endl;
  else if(x < 1800) cout << '2' << endl;
  else cout << '1' << endl;
  return 0;
}
