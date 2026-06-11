#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int ans = 0;
  while(b > 1){
    ++ans;
    b -= a-1;
  }
  cout << ans << endl;
}