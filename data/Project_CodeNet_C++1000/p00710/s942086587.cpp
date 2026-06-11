#include <iostream>
#include <algorithm>
using namespace std;

int n, r, p, c;
int h[51];

int main() {
  while(cin>>n>>r,n|r) {
    for(int i=1;i<=n;++i) {
      h[i] = n-i+1;
    }
    for(int i=0;i<r;++i) {
      cin>>p>>c;
      rotate(h+1, h+p, h+p+c);
    }
    cout << h[1] <<endl;
  }
  return 0;
}