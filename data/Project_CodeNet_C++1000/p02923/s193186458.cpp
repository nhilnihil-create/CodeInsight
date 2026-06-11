#include <iostream>
#include <string>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans = 0;
  int now = 0;
  int prev = -1;
  rep(i, n){
    int h;
    cin >> h;
    if (prev >= h) now++;
    else now = 0;
    ans = max(ans, now);
    prev = h;
  }
  cout << ans << endl;
  
  return 0;
}