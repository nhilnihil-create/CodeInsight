#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int m,d;
  cin >> m >> d;
  if(d==31) cout << 1 << endl;
  else if(d==30){
    if(m==4||m==6||m==9||m==11) cout << 1 << endl;
    else cout << 0 << endl;
  }
  else if(m==2&&d==28) cout << 1 << endl;
  else cout << 0 << endl;
}