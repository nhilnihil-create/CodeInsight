#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  if(n < 600) cout << 8 << endl;
  else if(n < 800) cout << 7 << endl;
  else if(n < 1000) cout << 6 << endl;
  else if(n < 1200) cout << 5 << endl;
  else if(n < 1400) cout << 4 << endl;
  else if(n < 1600) cout << 3 << endl;
  else if(n < 1800) cout << 2 << endl;
  else cout << 1 << endl;
}