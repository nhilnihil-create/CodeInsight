
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  int ans = 0, cnt = 0;
  int a[n];
  rep(i, n) cin >> a[i];
  rep(i, n - 1){
    if(a[i] >= a[i + 1]){
      cnt++;
      ans = max(ans, cnt);
    }
    else{
      cnt = 0;
    }
  }
  cout << ans << endl;

  return 0;
}