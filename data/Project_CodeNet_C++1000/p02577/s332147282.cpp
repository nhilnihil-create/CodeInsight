#include <iostream>
#include <string>
using namespace std;

int main(){
  string n;
  int ans = 0;
  cin >> n;
  for(char c : n){
    ans += (c - '0');
  }
  ans %= 9;
  if(ans == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}