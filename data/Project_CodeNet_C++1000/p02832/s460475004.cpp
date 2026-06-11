#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n;
  const int max_n = 2 * 1e5;
  int a[max_n+1];
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  bool flag = 0;
  int now = 1;
  for(int i = 0; i < n; i++){
    if(a[i] == now){
      flag = 1;
      now ++;
      ans ++;
    }
  }
  if(!flag) cout << -1 << endl;
  else cout << n - ans << endl;

  return 0;
}