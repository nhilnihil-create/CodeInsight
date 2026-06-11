#include<bits/stdc++.h>
using namespace std;

int main(){
  int x;
  cin >> x;
  int c = x / 100;
  if(100 * c <= x && 105 * c >= x) cout << 1 << endl;
  else cout << 0 << endl;
}