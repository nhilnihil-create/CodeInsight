#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
constexpr double EPS = 1e-8; 

int main(){
  int64 n;
  cin >> n;
  map<int64, int> mp;
  for(int64 i = 2; i * i <= n; ++i){
    while(n % i == 0){
      mp[i]++;
      n /= i;
    }
  }
  if(n != 1) mp[n]++;
  int ans = 0;
  for(auto i : mp){
    for(int j = 1; j <= i.second; ++j){
      ans++;
      i.second -= j;
    }
  }
  cout << ans << endl;
}