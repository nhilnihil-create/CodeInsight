#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n;
  const int max_n = 3 * 1e3;
  int l[max_n + 1];

  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  sort(l, l+n);

  long long ans = 0;
  for(int i = 0; i < n - 2; i++){
    for(int j = i + 1; j < n - 1; j++){
      for(int k = n - 1; k > j; k--){
        if(l[i] + l[j] > l[k]){
          ans += k - j;
          break;
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}