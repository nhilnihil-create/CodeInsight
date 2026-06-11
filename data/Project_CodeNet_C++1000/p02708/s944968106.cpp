#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
  const int max_n = 200000;
  const long long mod = 1000000000 + 7;
  int n, k;
  cin >> n >> k;

  long long s[max_n+1];
  s[0] = 0;
  for(int i = 1; i <= n; i++){
    s[i] = s[i-1] + i;
  }

  long long ans = 0;
  for(int i = k; i <= n+1; i++){
    if(i != n+1){
      long long max = s[n] - s[n - (i - 1) - 1];
      long long min = s[i - 1];
      long long res = max - min + 1;
      ans = (ans + res) % mod;
    }else{
      long long max = s[n];
      long long min = s[i - 1];
      long long res = max - min + 1;
      ans = (ans + res) % mod;
    }
    
  }
  cout << ans << endl;


  return 0;
}