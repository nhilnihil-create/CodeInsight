#include<iostream>
#include <string>
using namespace std;
int main(){
  int s,ans; cin >> s; string b; cin >> b; char st;
  ans = 1; st = b[0];
  for (int i = 1; i < s; i++){
    if (st!=b[i]) { ans += 1; st = b[i]; } }
  cout << ans << "\n";
  return 0;
}