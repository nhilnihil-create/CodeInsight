#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b; cin >> a >> b;
  if(b>a) swap(a,b);
  if(abs(a-b)%2!=0) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << (a+b)/2 << endl;
}