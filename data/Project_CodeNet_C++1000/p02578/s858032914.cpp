#include <iostream>
using namespace std;

int main(void){
  int n;
  long long ans;
  int h[200010];
  
  cin >> n;
  for (int i=0; i<n; i++) cin >> h[i];
  ans = 0;
  for (int i=1; i<n; i++){
    if (h[i-1]>h[i]){
      ans += h[i-1]-h[i];
      h[i] = h[i-1];
    }
  }
  cout << ans << endl;
  
  return 0;
}