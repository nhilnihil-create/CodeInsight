#include <iostream>
#include <vector>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  vector<int> ser;
  char prev = 'X';
  rep(i, n){
    if (prev == s[i]) ser.back()++;
    else ser.push_back(1);
    prev = s[i];
  }
  int x = ser.size();
  int ans;
  if (k - x/2 >= 0) ans = n - 1;
  else ans = n - x + 2 * k;
  cout << ans << endl;
  
  return 0;
}