#include<bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int i = 1;
  while(true) {
    c -= b;
    if(c < 1){
      cout << "Yes" << endl;
      return 0;
    }
    a -= d;
    if(a < 1){
      cout << "No" << endl;
      return 0;
    }
  }
}