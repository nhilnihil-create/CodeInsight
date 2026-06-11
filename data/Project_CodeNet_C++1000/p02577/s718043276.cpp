#include <bits/stdc++.h>

using namespace std;

int main(){
  char c;
  int result;
  while(cin >> c){
    result += c - '0';
    result %= 9;
  }
  cout << ((result == 0) ? "Yes" : "No");
  return 0;
}