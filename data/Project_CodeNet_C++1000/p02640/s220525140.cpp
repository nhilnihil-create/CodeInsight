#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int x,y;
  cin >> x >> y;
  int t=0,k=0;
  string ans;
  ans="No";
  
  for (t; t <= x; t++)
  {
    k=x-t;
    if(2*t+4*k==y){
      ans="Yes";
    }
  }
  
  cout << ans << endl;
  
  return 0;
}