#include<bits/stdc++.h>
using namespace std;

int main() {
  int kotae=0;
  for(int i=0;i<5;i++) {
    int x;
    cin >> x;
    if(x-1==i) {
      kotae++;
    } else {
      kotae++;
      break;
    }
  }
  cout << kotae << endl;
}