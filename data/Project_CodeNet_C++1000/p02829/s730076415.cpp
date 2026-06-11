#include <bits/stdc++.h>
using namespace std;

int main(){
  char A, B;
  cin >> A >> B;
  
  string ans = "123";
  ans.erase(remove(ans.begin(), ans.end(), A), ans.end());
  ans.erase(remove(ans.begin(), ans.end(), B), ans.end());
  
  cout << ans << endl;
}