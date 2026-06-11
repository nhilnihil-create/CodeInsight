#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin >> n;
  n--;
  char c = 'a';
  string ans = "";
  while(n >= 0){
    int x = n % 26;
    ans += (c + x);
    n /= 26;
    n--;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}