#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> h(n);
  int i;
  for(i=0;i<n;i++) cin >> h[i];
  int cnt = 0;
  for(i=0;i<n;i++){
    if(h[i]>=k) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}
