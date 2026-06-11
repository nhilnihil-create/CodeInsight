#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n,k;
  const int max_n = 2 * 1e5;
  int a[max_n + 1];
  cin >> n >> k;
  int max_a = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    max_a = max(max_a, a[i]);
  }
  int left = 0;
  int right = max_a;
  int x;
  int sum = 0;
  while(right - left > 1){
    sum = 0;
    x = (right + left) / 2;
    for(int i = 0; i < n; i++){
      if(a[i] == x) sum += a[i] / x - 1;
      else sum += a[i] / x;
    }
    // cout << "x= " << x << ", sum = " << sum << endl;
    if(sum <= k) right = x;
    else left = x;
    // if(right - left <= 1) break;
  }

  cout << right << endl;

  return 0;
}