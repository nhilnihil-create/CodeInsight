#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{

  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(i >= 1 && i <= 9) ans++;
    else if(i >= 100 && i <= 999) ans++;
    else if(i >= 10000 && i <= 99999) ans++;
    else if(i == 1000000) ans++;
  }
  cout << ans << endl;
  return 0;
}