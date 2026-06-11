#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n;
  cin >> n;
  int64_t ans = 0,m = 1;
  while(n!=0){
    n/=2;
    ans+=m;
    m*=2;
  }
  cout << ans << endl;
  return 0;
}