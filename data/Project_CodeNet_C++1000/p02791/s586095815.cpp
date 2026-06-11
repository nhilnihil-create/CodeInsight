#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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
  int a[n];
  rep(i, n) cin >> a[i];
  int m = a[0];
  int ans = 1;
  for(int i = 1; i < n; i++){
    if(a[i] <= m){
      ans++;
      m = a[i];
    }
  }
  cout << ans << endl;


  return 0;
}
