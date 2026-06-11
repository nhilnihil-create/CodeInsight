#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int k; cin >> k;
  int a, b; cin >> a >> b;
  bool ans = false;
  if(a%k==0)ans = true;
  else{
    if((a/k+1)*k<=b) ans = true;
  }
  if(ans)cout << "OK" << endl;
  else cout << "NG" << endl;
  return 0;
}