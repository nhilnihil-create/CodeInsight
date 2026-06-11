#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,l; cin >> n >> l;
  int sum = (n *(2 *l+n-1))/2;
  int min = 99999;
  int ans = 0;
  for(int i = 0; i < n; i++){
    int a = sum - (l + i); 
   // cout << sum << " " << a << endl;
    if(min > abs(sum - a)){
      min = abs(sum - a);
      ans = a;
    }
  }
  cout << ans;
  
}
