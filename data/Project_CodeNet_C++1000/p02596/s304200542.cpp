#include <bits/stdc++.h>
using namespace std;

int main(){
  long k;  cin >> k;
  if(k%2==0 || k%5==0){
    cout << "-1" << endl;
    return 0;
  }
  
  long sevens = 7, ans = 1;
  while(sevens % k){
    sevens = (sevens * 10 + 7) % k;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
