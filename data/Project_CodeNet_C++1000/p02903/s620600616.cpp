#include <bits/stdc++.h>
using namespace std;

int main() {
  long h,w,a,b;
  cin >> h >> w >> a >> b;
  for(long i=0;i<b;i++) {
    for(long j=0;j<a;j++) cout << 1;
    for(long j=0;j<w-a;j++) cout << 0;
    cout << endl;
  }
  for(long i=0;i<h-b;i++) {
    for(long j=0;j<a;j++) cout << 0;
    for(long j=0;j<w-a;j++) cout << 1;
    cout << endl;
  }
}