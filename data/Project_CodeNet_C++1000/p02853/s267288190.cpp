#include<bits/stdc++.h>
using namespace std;

int main() {
  int x,y;
  cin >> x >> y;
  int ans=8-min(x,4)-min(y,4);
  if(ans==6) {
    ans+=4;
  }
  cout << ans*100000 << endl;
}