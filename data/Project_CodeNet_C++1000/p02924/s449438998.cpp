#include<bits/stdc++.h>
using namespace std;

int64_t solve(int64_t n){
  int64_t ans=0;
  ans=(n-1)*n/2;
  return ans;
}

int main(){
  int64_t n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}