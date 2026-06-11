#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  if(n%max(h,w)==0) cout << n/max(h,w) << endl;
  else cout << n/max(h,w)+1 << endl;
}