#include <bits/stdc++.h>
using namespace std;
int main(){
  int l, r, d;
  cin >> l >> r >> d;
  cout << r/d - l/d + (l%d==0?1:0)<< endl;
}