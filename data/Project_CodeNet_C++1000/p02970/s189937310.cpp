#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{

  int n, d;
  cin >> n >> d;
  int ans = 0;
  int x = 0;
  while (x < n){
    x = x + d * 2 + 1;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
