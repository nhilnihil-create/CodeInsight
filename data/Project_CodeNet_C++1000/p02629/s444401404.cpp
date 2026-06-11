#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  ll n;
  cin >> n;
  string ans = "";
  while (n > 0) {
    int res = n % 26;
    n = n / 26;
    if (res == 0) {
      ans = 'z' + ans;
      n -= 1;
    } else {
      char c = 'a' + res - 1;
      ans = c + ans;
    } 
  } 
  cout << ans << endl;
} 
