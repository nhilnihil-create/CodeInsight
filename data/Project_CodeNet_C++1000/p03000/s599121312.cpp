#include <iostream>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  int sum = 0;
  int ans = 1;
  rep(i, n){
    int l;
    cin >> l;
    sum += l;
    if (sum > x) break;
    ans++;
  }
  cout << ans << endl;
  
  return 0;
}