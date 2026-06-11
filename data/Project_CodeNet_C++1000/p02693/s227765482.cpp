#include <bits/stdc++.h>
using namespace std;

int main() {
  int k,a,b;
  cin >> k >> a >> b;
  bool ans = false;
  
  for(int i=a; i<b+1;i++){
    if(i % k == 0)
      ans = true;
  }
  if(ans)
    cout << "OK" << endl;
  else
    cout << "NG" << endl;
}
