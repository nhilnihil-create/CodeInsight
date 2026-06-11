#include <iostream>
#include <vector>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(100, 0);
  rep(i, n+1){
    string s = to_string(i);
    int num = (s[0] - '0') * 10 + (s.back() - '0');
    a[num]++;
  }
  int ans = 0;
  rep(i, 101){
    if (i % 10 == 0) continue;
    int r = (i % 10) * 10 + (i / 10);
    ans += a[i] * a[r];
  }
  cout << ans << endl;
  
  return 0;
}