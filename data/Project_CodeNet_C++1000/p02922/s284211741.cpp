#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  int count = 0;
  int hole = 1;
  while(true){
    if(hole < b){
      hole += a-1;
      count++;
    }
    else
      break;
  }
  cout << count;
}
