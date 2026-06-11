#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

const int m=1000005;
int main(){
  int x;
  cin >> x;
  int y = ceil(x/1.08);
  if(int(y*1.08)==x) cout << y;
  else cout << ":(";

  return 0;
}
