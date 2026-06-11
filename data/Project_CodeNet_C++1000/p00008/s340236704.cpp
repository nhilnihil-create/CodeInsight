#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int ans;
int d[4];
int n;

// 1+2+4+8=15
void rec(int use) {
  if(use == 15) {
    if(d[0]+d[1]+d[2]+d[3]==n) ans++;
  }
  for(int i=0;i<4;i++) {
    if(use & (1<<i)) return;
    for(int j=0;j<10;j++) {
      d[i]=j;
      rec(use|(1<<i));
    }
  }
}

main() {
  while(cin>>n) {
    ans=0; rec(0);
    cout <<ans<<endl;
  }
}