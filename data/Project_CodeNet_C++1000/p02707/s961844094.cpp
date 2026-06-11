#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  int n, a[200010]={0};
  
  cin >> n;
  for (int i=2; i<=n; i++){
    int t; cin >> t;
    a[t]++;
  }
  for (int i=1; i<=n; i++){
    cout << a[i] << endl;
  }
//  cout << ans << endl;
  return 0;
}