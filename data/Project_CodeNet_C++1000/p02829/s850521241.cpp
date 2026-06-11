#include<bits/stdc++.h>
using namespace std;

int main() {
  int a,b,i=1; cin >> a >> b;
  while(i<4) {
    if(i != a && i != b){
      cout << i << endl;
      break;
    }
    else i++;
  }
}