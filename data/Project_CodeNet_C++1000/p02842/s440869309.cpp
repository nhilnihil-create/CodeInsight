#include<bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  int minx, maxx;
  if(n * 100 % 108 == 0) {
    minx = n * 100 / 108;
  }
  else {
    minx = n * 100 / 108 +1;
  }
  if((n + 1) * 100 % 108 == 0) {
    maxx = (n + 1) * 100 / 108;
  }
  else {
    maxx = (n + 1) * 100 / 108 +1;
  }
  if(maxx - minx <= 0) {
    cout << ":(" << endl;
  }
  else {
    cout << minx << endl;
  }
}