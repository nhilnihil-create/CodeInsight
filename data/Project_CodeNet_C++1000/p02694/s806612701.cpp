#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t x,ans=100;
  cin >> x;
  int i=0;
  while(1){
    ans = ans + ans/100;
    i++;
    if(ans>=x){
      break;
    }
  }
  cout << i << endl;
}