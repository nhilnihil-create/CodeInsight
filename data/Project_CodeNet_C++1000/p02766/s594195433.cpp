#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  string ans="";
  while(n){
    ans += n % k + '0';
    n /= k;
  }
  cout << ans.size() << endl;
  return 0;
}
