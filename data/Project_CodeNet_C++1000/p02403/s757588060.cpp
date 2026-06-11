#include <iostream>
#include <cstdio>
using namespace std;
int main () {
  int i;
  int h[999999],w[999999],x,y;

  for (i=0;i<999999;i++) {
    h[i] = 0;
    w[i] = 0;
  }
  i=0;
  while (1) {
    cin >> h[i] >> w[i];
    if (h[i]==0 || w[i]==0) { break;
    }
    i++;
  }
  for (i=0;i<999999;i++) {
    if (h[i] == 0 || w[i] == 0) break;
    for (y=0;y<h[i];y++) {
      for (x=0;x<w[i];x++) {
        cout << "#";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}