#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int x[5],ans = 0;
  for(int i = 0; i < 5; i++) 
    cin >> x[i];

  for(int i = 0; i < 5; i++) {
    if(x[i] == 0) 
      ans = i+1;
  }
  cout << ans << endl;
}